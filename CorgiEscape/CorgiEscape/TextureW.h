//
//  TextureW.hpp
//  SDL Tutorial
//
//  Created by ben jurenka on 3/27/20.
//  Copyright © 2020 ben jurenka. All rights reserved.
//

#ifndef TextureW_h
#define TextureW_h

#include <SDL.h>
#include <SDL_image.h>
#include <string>

class TextureW {
    public:
        //Initializes variables
        TextureW();

        //Deallocates memory
        ~TextureW();

        //Loads image at specified path
        bool loadFromFile( std::string path, SDL_Renderer* renderer );

        //Deallocates texture
        void free();

        //Renders texture at given point
        void render( int x, int y, SDL_Rect* clip, SDL_Renderer* renderer);
            
        void renderResize( int x, int y, SDL_Renderer* gRenderer, int w, int h,
                          double degrees, SDL_RendererFlip flip, SDL_Point* center, SDL_Rect* clip ) const;
        //Gets image dimensions
        int getWidth();
        int getHeight();

    private:
        //The actual hardware texture
        SDL_Texture* texture;

        //Image dimensions
        int width;
        int height;
};

#endif /* TextureW_h */
