//
//  Hazard.cpp
//  SDL Tutorial
//
//  Created by ben jurenka on 4/15/20.
//  Copyright © 2020 ben jurenka. All rights reserved.
//

#include "Hazard.h"
/*
Hazard::Hazard( ){
    onScreen = false;
    setRects( 0 );
    hazardType = 0;
    speed = 5;
    windowWidth = 600;
    printf("IN HAZARD DEFAULT CONSTRUCT");
}
*/
    //create hazard object, hazardIndex will change size of collider rects
Hazard::Hazard( int hazardIndex, int windowWidth ){
    this->onScreen = false;
    this->hazardType = hazardIndex;
    setRects(hazardIndex);
    this->windowWidth = windowWidth;
}

    //Shows the hazard collision rects on the screen
void Hazard::render( SDL_Renderer* renderer ){
    for(SDL_Rect r: hColliders){
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &r);
    }
}

void Hazard::reset( ){
    onScreen = false;
}
 void Hazard::move( int SPEED ) {
      for(SDL_Rect& r: hColliders){
          r.x -= SPEED;
          if( r.x < -120){
              for(SDL_Rect& offScreen: hColliders){
                  offScreen.x = windowWidth;
              }
              r.x = windowWidth;
              reset();
          }
     }
 }

void Hazard::move(int SPEED, int yLoc){
    int birdHeight = 10;
    for(SDL_Rect& r: hColliders){
        r.x -= SPEED;
        r.y -= yLoc;
        if( r.x < -120){ //offscreen
            for(SDL_Rect& offScreen: hColliders){
                offScreen.x = windowWidth;
                offScreen.y = birdHeight;
                birdHeight += 10;
            }
            reset();
        }
    }
}

void Hazard::setXLoc(int xLoc){
    xLoc = 600 - xLoc;
    for(auto& e: hColliders){
        e.x -= xLoc;
    }
}

void Hazard::setOnScreen( bool onScreen ){
    this->onScreen = onScreen;
}
bool Hazard::getOnScreen( ){
    return onScreen;
}
int Hazard::getHazardType( ){
    return hazardType;
}
void Hazard::setRects( int hazardIndex ){
    SDL_Rect rect;
    switch (hazardIndex) {
        case 0:
            //daisy
                                        //x ,  y   ,w  , h
            renderOffset = -25;
            hColliders.push_back(rect = {600, 178, 20, 10});
            hColliders.push_back(rect = {605, 188, 20, 10});
            hColliders.push_back(rect = {610, 198, 20, 10});
            hColliders.push_back(rect = {614, 208, 20, 40});
            
            break;
            
        case 1:
            //fence
            hColliders.push_back(rect = {windowWidth, 200, 30, 10});
            hColliders.push_back(rect = {windowWidth, 200, 30, 10});
            hColliders.push_back(rect = {windowWidth, 200, 30, 10});
            hColliders.push_back(rect = {windowWidth, 200, 30, 10});

            break;
        case 2:
            //bird
            hColliders.push_back(rect = {windowWidth, 10, 20, 10});
            hColliders.push_back(rect = {windowWidth, 20, 20, 10});
            hColliders.push_back(rect = {windowWidth, 30, 20, 10});
            hColliders.push_back(rect = {windowWidth, 40, 20, 10});

            break;
        case 3:
            //hoop
            hColliders.push_back(rect = {windowWidth, 170, 20, 10});
            hColliders.push_back(rect = {windowWidth, 180, 20, 10});
            hColliders.push_back(rect = {windowWidth, 190, 20, 10});
            hColliders.push_back(rect = {windowWidth, 200, 20, 10});

            break;
    }
}

int Hazard::getYLoc(){
    return hColliders.at(0).y;
}
int Hazard::getXLoc(){
    return hColliders.at(0).x;
}
