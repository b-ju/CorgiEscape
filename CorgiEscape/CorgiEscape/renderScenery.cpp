//
//  renderScenery.cpp
//  Graphics Example
//
//  Created by ben jurenka on 7/8/20.
//  Copyright © 2020 ben jurenka. All rights reserved.
//

#include <stdio.h>
#include "Control.h"

void Control::renderScenery(){
        //********* Render Clouds ***********
    SDL_SetRenderDrawColor(renderer, 135, 206, 235, 255);
    SDL_RenderFillRect(renderer, &sky);
        //********* Render Mountains ********
    mountain_texture.render(0, -20, &mountain_frames[frame_count % MF_NUM], renderer);
    
      //********* Render Tress ***********
    if(rand.at(frame_count) > 80){
        plantVec.at(orderOfPlants.at(plantIndex % orderOfPlants.size()))->setOnScreen(true);
        ++plantIndex;
    }
    for( int i = NUMPLANTS - 1; i >= 0; --i ){
        if(plantVec.at(i)->getOnScreen() == true){ // big plants
            if( plantVec.at(i)->getPlantType() == 0 || plantVec.at(i)->getPlantType() == 1 || plantVec.at(i)->getPlantType() == 4){
                plant_texture.renderResize(plantVec.at(i)->getXLoc(), -220, renderer, 300, 450, 0, SDL_FLIP_NONE, nullptr, &plant_frames[plantVec.at(i)->getPlantType()]);
            } else if ( plantVec.at(i)->getPlantType() == 5){ // flowering cacti
                plant_texture.renderResize(plantVec.at(i)->getXLoc(), 100, renderer, 80, 120, 0, SDL_FLIP_NONE, nullptr, &plant_frames[5]);
            } else if (plantVec.at(i)->getPlantType() == 6 ){ // fat cacti
                plant_texture.renderResize(plantVec.at(i)->getXLoc(), 100, renderer, 80, 120, 0, SDL_FLIP_NONE, nullptr, &plant_frames[6]);
            } else if (plantVec.at(i)->getPlantType() == 10 ) { // cloud
                hazard_textures.at(2).render(plantVec.at(i)->getXLoc(), cloud_Yloc, &hazard_frames[2], renderer); 
            } else if ( plantVec.at(i)->getPlantType() == 11 ) { // cloud
                hazard_textures.at(3).render(plantVec.at(i)->getXLoc(), cloud_Yloc, &hazard_frames[3], renderer);
            } else {
                plant_texture.render( plantVec.at(i)->getXLoc(), -79, &plant_frames[plantVec.at(i)->getPlantType()], renderer);
            }
                if(plantVec.at(i)->getPlantType() == 10 || plantVec.at(i)->getPlantType() == 11){
                    plantVec.at(i)->move(1); //move clouds
                } else {
                    plantVec.at(i)->move(SPEED - 1);
                }
        }
    }
    //********* Render Grass ***********
    for( int i = 0; i < 14; i++){
            ground_texture.renderResize(i * 65 + groundLoc, 200, renderer, 100, 100, 0, SDL_FLIP_NONE, nullptr, &groundFrame);
    }
            groundLoc -= SPEED;
    if(groundLoc < -105){
            groundLoc = -40;
    }// needs to go from -40 to -104

    //********* Fence *************
    if(fenceLoc > -600){
        fence_texture.renderResize(fenceLoc, 169, renderer, 600, 100, 0, SDL_FLIP_NONE, nullptr, nullptr);
        fenceLoc -= SPEED;
    }
}
