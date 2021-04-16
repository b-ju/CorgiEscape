//
//  send.cpp
//  SDL Tutorial


#include "Control.h"
//                  tex: the picture to render
//                 frame: the portion of pic to render
//                  hazard: hazard object to move at same rate as tex
void Control::resetLevel( ) {
    music.pauseMusic();
    lives -= 1;
    SDL_Delay(100);
    frame_count = 0;
    fenceLoc = 0;
    jump_count = 35;
    height = 135;
    Jump(jump_count, height, corgi);
    if( lives == 0){
            highscore();
    }
    startScreen = true;
    for(int i = 0; i < NUMHAZ; i++){
        hazardVec.at(i).reset();
    }
    for(int i = 0; i < NUMPLANTS; i++){
        plantVec.at(i)->reset();
    }
}

void Control::sendHazard( int type )  {
    //render image on screen
    hazard_textures.at(type).render(hazardVec.at(type).getXLoc() + hazardVec.at(type).getRO(),
                                  hazardVec.at(type).getYLoc() + hazardVec.at(type).getRO(),
                                  &hazard_frames[type], renderer);
    //move collision rects
    hazardVec.at(type).move(SPEED);
    //TESTING
    hazardVec.at(type).render(renderer);
}

void Control::sendHazard(int type, int& flyCount){
    hazardVec.at(type).render(renderer);
    if(flyCount < 10) {
        bird_texture.render(hazardVec.at(type).getXLoc(), hazardVec.at(type).getYLoc(), &bird_frames[flyCount % 4], renderer);
        hazardVec.at(type).move(SPEED,5);
    } else if(flyCount < 15){
        bird_texture.render(hazardVec.at(type).getXLoc(), hazardVec.at(type).getYLoc(), &bird_frames[flyCount % 4], renderer);
        hazardVec.at(type).move(SPEED,0);
    } else if(flyCount < 20){
        bird_texture.render(hazardVec.at(type).getXLoc(), hazardVec.at(type).getYLoc(), &bird_frames[flyCount % 4], renderer);
        hazardVec.at(type).move(SPEED,5);
    } else { // if flyCount == 20 reset to
        flyCount = 0;
    }
   flyCount++;
}
