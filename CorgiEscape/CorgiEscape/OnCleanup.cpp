//
//  OnCleanup.cpp
//  SDL Tutorial
//
//  Created by ben jurenka on 3/27/20.
//  Copyright © 2020 ben jurenka. All rights reserved.
//

#include "Control.h"

void Control::OnCleanup(){

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    hazardVec.clear();

    for (int i = 0; i < plantVec.size(); ++i) {
      delete plantVec[i]; // Calls ~object and deallocates *tmp[i
    }
    plantVec.clear();
    
    //Free loaded images
    corgi_texture.free();
    fence_texture.free();
    mountain_texture.free();
    for(auto h: hazard_textures){
        h.free();
    }
    fence_texture.free();
    lifeTex.free();
    TTF_CloseFont(font);
    SDL_CloseAudio();
    music.closeMusic();
    fartSound.closeMusic();
    jumpSound.closeMusic();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
    Mix_Quit();
    printf("clean up finished.\n");
}
