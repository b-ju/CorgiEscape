//
//  Corgi.hpp
//  SDL Tutorial
//
//  Created by ben jurenka on 4/14/20.
//  Copyright © 2020 ben jurenka. All rights reserved.
//

#ifndef Corgi_hpp
#define Corgi_hpp
#include <SDL.h>
#include <vector>
#include <stdio.h>

class Corgi{
    public:
            //Initializes the variables
            Corgi(  );

            //Moves the corgi by calling
            void move( int count);
    

            //Shows the corgis collision rects on the screen
            void render( SDL_Renderer* renderer );
                
            //reset to walking position
            void resetColliders();
            
            //check that corgi collision boxs are not overlapping another set of collision boxes
            bool checkCollision( const std::vector<SDL_Rect>& b ) ;
        
            //Gets the collision boxes
            std::vector<SDL_Rect>& getColliders();

        private:
            
            bool firstFrameOfJump;

            //corgi's collision boxes
            std::vector<SDL_Rect> mColliders;
            
          //shift all rects in
            void shiftColliders(int movement);
};


#endif /* Corgi_hpp */
