//
//  Hazard.h
//  SDL Tutorial
//
//  Created by ben jurenka on 4/15/20.
//  Copyright © 2020 ben jurenka. All rights reserved.
//

#ifndef Hazard_h
#define Hazard_h

#include <SDL.h>
#include <vector>
#include <stdio.h>
#include "TextureW.h"

class Hazard{
    public:
        Hazard( );
        //create hazard object, hazardIndex will change size of collider rects
        Hazard( int hazardIndex, int windowWidth);
        void move( int SPEED );
        void move(int SPEED, int yLoc);
        void render( SDL_Renderer* renderer );
        std::vector<SDL_Rect>& getColliders(){
            return hColliders;
        }
        void reset();
        void setOnScreen(bool onScreen);
        bool getOnScreen( );
        int getHazardType( );
        int getYLoc();
        int getXLoc();
        void setXLoc(int xLoc);
        int getRO(){
            return renderOffset;
        }

    private: 
        std::vector<SDL_Rect> hColliders;
        bool onScreen = false;
        int speed = 6;
        int hazardType;
        int windowWidth = 600;
        void setRects( int hazardIndex );
        int renderOffset = 0;
};
#endif /* Hazard_h */
