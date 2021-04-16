//
//  TextureW.cpp
//  SDL Tutorial
//
//  Created by ben jurenka on 3/27/20.
//  Copyright © 2020 ben jurenka. All rights reserved.
//

#include "TextureW.h"
        TextureW::TextureW(){
           texture = NULL;
           width = 0;
           height = 0;
       }

       //Deallocates memory
       TextureW:: ~TextureW(){
           free();
       }

       //Loads image at specified path
       bool TextureW::loadFromFile( std::string path, SDL_Renderer* renderer ){
           //Get rid of preexisting texture
           free();

           //The final texture
           SDL_Texture* newTexture = NULL;

           //Load image at specified path
           SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
           if( loadedSurface == NULL ) {
               printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
           }
               //Create texture from surface pixels
           newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
           
           if( newTexture == NULL ) {
               printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
           } else {
                //Set image dimensions
                width = loadedSurface->w;
                height = loadedSurface->h;
           }
            
           //Get rid of old loaded surface
           SDL_FreeSurface( loadedSurface );
    
           //Return success
           texture = newTexture;
           return texture != NULL;
       }

       //Deallocates texture
       void  TextureW::free(){
           //Free texture if it exists
           if( texture != NULL ) {
               SDL_DestroyTexture( texture );
               texture = NULL;
               width = 0;
               height = 0;
           }
       }

       //Renders texture at given point
       void  TextureW::render( int x, int y, SDL_Rect* clip, SDL_Renderer* renderer){
           //Set rendering space and render to screen
            SDL_Rect renderQuad = { x, y, width, height };

            //Set clip rendering dimensions
            if( clip != NULL ) {
                renderQuad.w = clip->w;
                renderQuad.h = clip->h;
            }

            //Render to screen
           SDL_RenderCopy( renderer, texture, clip, &renderQuad );
       }


void TextureW::renderResize( int x, int y, SDL_Renderer* renderer, int w, int h, double degrees, SDL_RendererFlip flip, SDL_Point* center, SDL_Rect* clip ) const { 
    SDL_Rect renderQuad = { x,y,w, h };
    SDL_RenderCopyEx( renderer, texture, clip, &renderQuad, degrees, center, flip );
}
       //Return image dimensions
       int TextureW::getWidth(){
               return width;
       }

       int TextureW::getHeight(){
               return height;
       }
