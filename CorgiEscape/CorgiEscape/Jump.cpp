//
//  Jump.cpp
//  SDL Tutorial
//
//  Created by ben jurenka on 3/28/20.
//  Copyright © 2020 ben jurenka. All rights reserved.
//

#include "Control.h"

void Control::Jump(int& count, int& height, Corgi& c){
    if(count == 3){
        fartSound.playMusic();
    }
    if( count < 10 ){
        height -= 10;
        corgi_texture.render(FROM_LEFT, height, &corgi_frames[ 0 ],renderer);
        c.move(count);
        count++;

    } else if( count < 16){
        height -= 5;
        corgi_texture.render(FROM_LEFT, height, &corgi_frames[ 0 ],renderer);
        c.move(count);
        count++;
        
    } else if( count < 17){
        corgi_texture.render(FROM_LEFT, height      , &corgi_frames[ 0 ],renderer);
        c.move(count);
        count++;
        
    } else if( count < 23){
        height += 5;
        corgi_texture.render(FROM_LEFT, height, &corgi_frames[ 0 ],renderer);
        c.move(count);
        count++;
        
    } else if( count < 33 ){
        height += 10;
        corgi_texture.render(FROM_LEFT, height, &corgi_frames[ 0 ],renderer);
        c.move(count);
        count++;
    
    } else {
        count = 0;
        height = 135;
        jump = false;
        c.resetColliders();
    }
}
