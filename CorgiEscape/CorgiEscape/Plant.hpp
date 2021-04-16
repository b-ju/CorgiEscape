//
//  Plant.hpp
//  Graphics Example
//
//  Created by ben jurenka on 7/12/20.
//  Copyright © 2020 ben jurenka. All rights reserved.
//

#ifndef Plant_hpp
#define Plant_hpp

#include <SDL.h>
#include <vector>
#include <stdio.h>
#include "TextureW.h"

class Plant {
public:
    Plant( );
    //create hazard object, hazardIndex will change size of collider rects
    Plant( int plantIndex, int speed, int windowWidth );
    void move( int s );
    void reset();
    void setOnScreen(bool onScreen);
    bool getOnScreen( );
    int getXLoc();
    void setXLoc(int x );
    int getPlantType( );
    int getSpeed();
    
    private:
        
    bool onScreen;
    int speed;
    int plantType;
    int xLoc;
    int WINDOW_WIDTH;
};


#endif /* Plant_hpp */
