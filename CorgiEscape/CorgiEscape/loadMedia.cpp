//
//  loadMedia.cpp
//  SDL Tutorial
//
//  Created by ben jurenka on 3/27/20.
//  Copyright © 2020 ben jurenka. All rights reserved.
//

#include "Control.h"

//*************** LoadMedia ****************//
bool Control::loadMedia( ){
    bool success = true;
    hazard_textures.resize(4);
    if (
    
    loadSprites("bird_hazard.png", renderer, bird_texture, bird_frames) &&
    loadSprites("corgo.png", renderer, corgi_texture, corgi_frames) &&
    loadSprites("hazards_small.png", renderer, hazard_textures.at(0), hazard_frames) &&
    loadLandscape("hills.png",renderer, mountain_texture, mountain_frames,  MF_NUM, 0, 1, WINDOW_WIDTH, WINDOW_HEIGHT) &&
    loadLandscape("plants.png", renderer, plant_texture, plant_frames, PF_NUM, 0, 100, 100, WINDOW_HEIGHT) &&
    setFont("text.ttf", 32) )
    
    {
        success = true;
    } else {
        success = false;
    }
    
    loadPic("fence.png", renderer, fence_texture);
    loadPic("ground.png", renderer, ground_texture);     
    loadPic("life-meter-icon.png", renderer, lifeTex);
    loadPic("hoop.png", renderer, hoop_texture);
    music.setMusicPath("background.ogg");
    fartSound.setChunkPath("fart.ogg");
    jumpSound.setChunkPath("jump.wav");
    

    return success;
}


bool Control::loadLandscape( std::string path, SDL_Renderer* renderer, TextureW& tex, SDL_Rect* rect,
                            int num_frames, int pixels_from_top, int pixels_per_frame, int w, int h ) {
        bool success = true;
        if( !tex.loadFromFile( path, renderer )) {
            printf( "Failed to load fence texture!\n" );
            success = false;
        } else {
            int frame_pos = 0;
            for(int i = 0; i < num_frames; i++) {
                rect[ i ].x = frame_pos;
                rect[ i ].y = pixels_from_top;
                rect[ i ].w = w; // 600
                rect[ i ].h = h; // 300
                frame_pos += pixels_per_frame;
            }
        }
    
    if(success) {
            printf("Loaded %s.\n", path.c_str());
    }
    
    return success;
}

//****************** Load Sprites **********************
bool Control::loadSprites(std::string path, SDL_Renderer* renderer, TextureW& tex, SDL_Rect* clips) {
    //Loading success flag
    bool success = true;
    const int sideLength = 100;
    //Load sprite sheet texture
    if( !tex.loadFromFile( path, renderer )) {
        printf( "Failed to load sprite sheet texture!\n" );
        success = false;
    } else {
        //Set top left sprite
        clips[ 0 ].x =  0;
        clips[ 0 ].y =  0;
        clips[ 0 ].w = sideLength;
        clips[ 0 ].h = sideLength;

        //Set top right sprite
        clips[ 1 ].x = sideLength;
        clips[ 1 ].y =   0;
        clips[ 1 ].w = sideLength;
        clips[ 1 ].h = sideLength;
        
        //Set bottom left sprite
        clips[ 2 ].x =   0;
        clips[ 2 ].y = sideLength;
        clips[ 2 ].w = sideLength;
        clips[ 2 ].h = sideLength;

        //Set bottom right sprite
        clips[ 3 ].x = sideLength;
        clips[ 3 ].y = sideLength;
        clips[ 3 ].w = sideLength;
        clips[ 3 ].h = sideLength;
    }
    if(success){
        printf("Loaded %s.\n", path.c_str());
    }
    return success;
}

bool Control::loadPic(std::string path, SDL_Renderer* renderer, TextureW& tex ){
    bool success = true;
    
    if( !tex.loadFromFile( path, renderer )) {
        printf( "Failed to load sprite sheet texture!\n" );
        success = false;
    }
    return success;
}

// END LOADMEDIA ///
