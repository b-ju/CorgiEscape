//
//  Walk.cpp
//  SDL Tutorial
//
//  Created by ben jurenka on 3/28/20.
//  Copyright © 2020 ben jurenka. All rights reserved.
//

#include "Control.h"

void Control::Walk(int& walk_count, int& height ){
    if(walk_count < 4){
        corgi_texture.render(FROM_LEFT - 6, height, &corgi_frames[ 1 ], renderer);
        walk_count++;
    } else if( walk_count < 7){
        corgi_texture.render(FROM_LEFT, height, &corgi_frames[ 3 ], renderer);
        walk_count++;
        if(walk_count == 6){
            walk_count = 0;
        }
    }
}
