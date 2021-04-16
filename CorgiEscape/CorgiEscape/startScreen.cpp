//
//  startScreen.cpp
//  SDL Tutorial
//
//  Created by ben jurenka on 7/5/20.
//  Copyright © 2020 ben jurenka. All rights reserved.
//

#include <stdio.h>
#include "Control.h"

void Control::displayStartScreen( ) {
    bool stay = true;
    bool highlight = false;
    loadButton( highlight );

        //********* Clouds ***********
        SDL_SetRenderDrawColor(renderer, 135, 206, 235, 255);
        SDL_RenderFillRect(renderer, &sky);
       // cloud_texture.render(0, 0, &cloud_frames[2], renderer);
        //*********  Mountains ********
        mountain_texture.render(0, -20, &mountain_frames[0], renderer);
        //*********  Grass ***********
        for( int i = 0; i < 14; i++){
            ground_texture.renderResize(i * 65 + groundLoc, 200, renderer, 100, 100, 0, SDL_FLIP_NONE, nullptr, &groundFrame);
        }
  
        //***********  Fence  *************
        fence_texture.renderResize(0, 169, renderer, 600, 100, 0, SDL_FLIP_NONE, nullptr, &fence_frame);

        //*********** Corgi ************
        corgi.resetColliders();
        corgi_texture.render(FROM_LEFT - 6, height, &corgi_frames[ 2 ], renderer);
        //******TEST HOOP*******
    
        hoop_texture.renderResize(185, 120, renderer, 50, 140, 0, SDL_FLIP_NONE, nullptr, &hoop_stand_frame);
        hoop_texture.renderResize(150, 69, renderer, 80, 140, 0, SDL_FLIP_NONE, nullptr, &hoop_frame);
        //******TEST BIRD*******
    bird_texture.render(200, 150, &bird_frames[0], renderer);
    bird_texture.render(250, 150, &bird_frames[1], renderer);
    bird_texture.render(300, 150, &bird_frames[2], renderer);
    bird_texture.render(350, 150, &bird_frames[3], renderer);

    
    //*********** Button ***************
        loadButton( highlight );
       
        SDL_RenderPresent(renderer);
        /*if( Event->type == SDL_KEYDOWN) {
        switch( Event->key.keysym.sym ) {
            case SDLK_UP:*/
        while(stay){
        while( SDL_PollEvent(&Event) ) {
            SDL_RenderClear(renderer);
            if(Event.type == SDL_KEYUP ){
                if(Event.key.keysym.sym == SDLK_UP){
                    stay = false;
                }
            } else if (Event.type == SDL_KEYDOWN){
                if(Event.key.keysym.sym == SDLK_UP){
                    highlight = true;
                }
            } else if(Event.type == SDL_QUIT){
                stay = false;
                Control::Running = false;
            }
        }
    }
}

 
void Control::loadButton( bool highlight ) {
    if( highlight) {
        setFont("text.ttf", 40);
        renderText("Corgi", 40, 360, 20, nullptr, 15, nullptr, SDL_FLIP_NONE, 252, 185, 31);
        setFont("text.ttf", 50);
        renderText("ESCAPE!", 50, 350, 60, nullptr, 15, nullptr, SDL_FLIP_NONE, 252, 185, 31);
        setFont("text.ttf", 22);
        renderText("(press up)", 22, 400, 120, nullptr, 15, nullptr, SDL_FLIP_NONE, 252, 185, 31);
    } else {
        setFont("text.ttf", 40);
        renderText("Corgi", 40, 360, 20, nullptr, 15, nullptr, SDL_FLIP_NONE, 255, 255, 255);
        setFont("text.ttf", 50);
        renderText("ESCAPE!", 50, 350, 60, nullptr, 15, nullptr, SDL_FLIP_NONE, 255, 255, 255);
        setFont("text.ttf", 22);
        renderText("(press up)", 22, 400, 120, nullptr, 15, nullptr, SDL_FLIP_NONE, 255, 255, 255);
    }
}
