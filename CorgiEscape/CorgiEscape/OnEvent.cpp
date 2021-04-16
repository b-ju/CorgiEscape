//
//  OnEvent.cpp
//  SDL Tutorial
//
//  Created by ben jurenka on 3/12/20.
//  Copyright © 2020 ben jurenka. All rights reserved.
//


#include "Control.h"

void Control::OnEvent(SDL_Event *Event){
    if(Event->type == SDL_QUIT) {
        Running = false;
    }
     //User presses a key
    else if( Event->type == SDL_KEYDOWN) {
        switch( Event->key.keysym.sym ) {
            case SDLK_UP:
                jump = true;
                //Mix_PlayMusic( music, -1 );
            break;
                
            case SDLK_SPACE:
            break;
            
            default:
            break;
        }
    }
}

