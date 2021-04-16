
#include <stdio.h>
#include "Control.h"
bool Control::setFont(std::string path, int font_size){
    bool success = true;
    font = TTF_OpenFont(path.c_str(), font_size);
    if(!font){
        success = false;
    }
    return success;
}

//renders a string to window
bool Control::renderText(std::string sentence, int font_size, int x, int y, SDL_Rect* clip,
                         double angle, SDL_Point* center, SDL_RendererFlip flip, Uint8 r, Uint8 g, Uint8 b ) {
                //set font to the font that will be used, and size of text
        bool success = true;
        SDL_Surface* surface = nullptr;
        SDL_Color textColor = {
            r, g, b , 255
        };

              //make sure font loaded successfully
        if( !font ){
            printf( "Failed to load font! SDL_ttf Error: %s\n", TTF_GetError() );
            return false;
        } else {
                //set surface from: font, a c style string, and text color
          surface = TTF_RenderText_Solid( font, sentence.c_str(), textColor );
        }
                //make sure surface loaded successfully
         if( surface == NULL ) {
             printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
             return false;
         }
                //Create texture from surface pixels
        SDL_Texture* texture = SDL_CreateTextureFromSurface( renderer, surface );
        
                //make sure texture loaded successfully
         if( texture == NULL ){
             printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
             return false;
         } else {
                 //if text_texture loaded successfully: Get image dimensions
                     text_Width = surface->w;
                     text_Height = surface->h;
        }
                //done with this surface, so free it
        SDL_FreeSurface( surface );
                //initialize a rect for SDL_RenderCopyEx
        SDL_Rect renderQuad = {
            x, y, text_Width, text_Height
        };
                //Set clip rendering dimensions
        if( clip != nullptr ) {
            renderQuad.w = clip->w;
            renderQuad.h = clip->h;
        }
                //Render to screen
        SDL_RenderCopyEx( renderer, texture, clip, &renderQuad, angle, center, flip );
    return success; 
}

