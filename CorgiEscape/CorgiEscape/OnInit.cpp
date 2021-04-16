//
//  OnInit.cpp
//  SDL Tutorial
//
//  Created by ben jurenka on 3/12/20.
//  Copyright © 2020 ben jurenka. All rights reserved.
//
//initialize: SDL, window, renderer, SDL_IMG

#include "Control.h"

bool Control::OnInit(){
      //Initialize SDL
      if( SDL_Init( SDL_INIT_EVERYTHING )  < 0 ) {
          printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
          return false;
      }  else {
          //Set texture filtering to linear
          if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) ) {
              printf( "Warning: Linear texture filtering not enabled!" );
          }
      }
    
    //Create window
    window = SDL_CreateWindow( "CORGI ESCAPE", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE  );

    if( window == NULL )  {
              printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
              return false;
    } else {
        //Create renderer for window
        renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
        
        if( renderer == NULL ) {
            printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
            return false;
        }
    }
    
    
    //Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )  {
        printf( "SDL_image could not initialize! SDL_mage Error: %s\n", IMG_GetError() );
        return false;
    }
    
    //Initialize text loading
    if( TTF_Init() == -1 ) {
        printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
        return false;
    }
    
    if(music.initMusic() == -1){
        return false;
    }
 
      return true;
  }
