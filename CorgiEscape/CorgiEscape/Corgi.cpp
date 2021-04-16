//
//  Corgi.cpp
//  SDL Tutorial
//
//  Created by ben jurenka on 4/14/20.
//  Copyright © 2020 ben jurenka. All rights reserved.
//

#include "Corgi.hpp"

Corgi::Corgi(  ) {
    //Create the necessary SDL_Rects
    mColliders.resize( 5 );
    firstFrameOfJump = false;
                      // x,  y,   w,  h
    mColliders.at(0) = { 60, 150, 20, 25};
    mColliders.at(1) = { 58, 171, 39, 10};
    mColliders.at(2) = { 22, 195, 70, 10};
    mColliders.at(3) = { 22, 204, 70, 10};
    mColliders.at(4) = { 18, 220, 70, 10};
}

void Corgi::move( int count ) {
    
    //count is coming from jump method so this will match up with picture renderered
    if( count < 10 ){
        shiftColliders(-10);
    } else if( count < 15){
          shiftColliders(-5);
    } else if( count < 16){
          //do nothing
    } else if( count < 21){
          shiftColliders(5);
    } else if( count < 31 ){
          shiftColliders(10);
    }
    
    // if this is the the first frame of jump method
    // set firstFrameOfJump to true so variables that
    //only change once can change
    
    if(count == 0){
        firstFrameOfJump = true;
    }
}

//only called in Control::Jump method
void Corgi::shiftColliders(int movement){
                //for every rect in mColliders
    for(SDL_Rect& r: mColliders){
                //change y number everytime this is called
        r.y += movement;
    }
                //change other variables on first call during jump cycle
    if(firstFrameOfJump){                //x,   y,   w,  h
        mColliders.at(0) = { 60, mColliders.at(0).y, 30, 25};
        mColliders.at(1) = { 68, mColliders.at(1).y, 39, 10};
        mColliders.at(2) = { 22, mColliders.at(2).y, 70, 10};
        mColliders.at(3) = { 30, mColliders.at(3).y, 70, 10};
        mColliders.at(4) = { 15, mColliders.at(4).y - 15, 90, 10};
        // end of FirstFrame so set to false;
        firstFrameOfJump = false;
    }
}

//reset all rects
void Corgi::resetColliders(){
    mColliders.at(0) = { 60, 150, 20, 25};
    mColliders.at(1) = { 58, 171, 39, 10};
    mColliders.at(2) = { 22, 195, 70, 10};
    mColliders.at(3) = { 22, 204, 70, 10};
    mColliders.at(4) = { 18, 220, 70, 10};
}

std::vector<SDL_Rect>& Corgi::getColliders() {
    return mColliders;
}

bool Corgi::checkCollision( const std::vector<SDL_Rect>& b ) 
{
    std::vector<SDL_Rect>& a = mColliders;
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Go through the A boxes
    for( int Abox = 0; Abox < a.size(); Abox++ )
    {
        //Calculate the sides of rect A
        leftA = a[ Abox ].x;
        rightA = a[ Abox ].x + a[ Abox ].w;
        topA = a[ Abox ].y;
        bottomA = a[ Abox ].y + a[ Abox ].h;

        //Go through the B boxes
        for( int Bbox = 0; Bbox < b.size(); Bbox++ )
        {
            //Calculate the sides of rect B
            leftB = b[ Bbox ].x;
            rightB = b[ Bbox ].x + b[ Bbox ].w;
            topB = b[ Bbox ].y;
            bottomB = b[ Bbox ].y + b[ Bbox ].h;

            //If no sides from A are outside of B
            if( ( ( bottomA <= topB ) || ( topA >= bottomB ) || ( rightA <= leftB ) || ( leftA >= rightB ) ) == false )
            {
                //A collision is detected
                printf("Collision detected - Corgi");
                return true;
            }
        }
    }
    //If neither set of collision boxes touched
    return false;
}

//render collision boxs to make sure they align with
void Corgi::render( SDL_Renderer* renderer ){
    SDL_SetRenderDrawColor( renderer, 0, 42, 42, 255 );
    for( auto e: mColliders ) {
        SDL_RenderFillRect( renderer, &e );            //put rectangle into renderer
    }
}

