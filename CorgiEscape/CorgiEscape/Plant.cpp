//
//  Plant.cpp
//  Graphics Example
//
//  Created by ben jurenka on 7/12/20.
//  Copyright © 2020 ben jurenka. All rights reserved.
//

#include "Plant.hpp"

Plant::Plant( ){
    onScreen = false;
    plantType = 0;
    speed = 5;
   // printf("IN HAZARD DEFAULT CONSTRUCT");
    xLoc = 0;
}

    //create hazard object, hazardIndex will change size of collider rects
Plant::Plant( int plantIndex, int speed, int windowWidth ){
    this->onScreen = false;
    this->speed = speed;
    this->plantType = plantIndex;
    this->xLoc = windowWidth;
    this->WINDOW_WIDTH = windowWidth;
  //  printf("IN HAZARD PARAM CONSTRUCT\n");
}

int Plant::getSpeed(){
    return speed;
}

void Plant::move( int s ){
    xLoc -= s;
    if( plantType == 0 || plantType == 1 || plantType == 4){
        if( xLoc < -300){
            reset();
        }
    } else if( xLoc < -100){
        reset();
    }
}

void Plant::reset( ){
    this->xLoc = WINDOW_WIDTH;
    this->onScreen = false;
}

void Plant::setOnScreen( bool onScreen ){
    this->onScreen = onScreen;
}
bool Plant::getOnScreen( ){
    return onScreen;
}

int Plant::getPlantType( ){
    return plantType;
}

int Plant::getXLoc(){
    return xLoc;
}
void Plant::setXLoc(int x ){
    this->xLoc = x;
}

