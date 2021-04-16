//
//  highscore.cpp
//  Graphics Example
//
//  Created by ben jurenka on 7/17/20.
//  Copyright © 2020 ben jurenka. All rights reserved.
//
// basic file operations
#include <iostream>
#include <fstream>
#include "Control.h"
using namespace std;

void Control::highscore () {
    bool stay = true;
   
    SDL_RenderClear(renderer);
    std::vector<int> scores(25);
    for(auto& i: scores){
        i = 0;
    }
    std::string line;

    ifstream fromfile ("/Users/benjurenka/Library/Developer/Xcode/DerivedData/Graphics_Example-fcszsdjyxjkgjsepbppfaaiqevas/Build/Products/Debug/highscore.txt");
    scores.push_back(std::stoi(score_str));
    
    if( fromfile.is_open() ) {
        while( getline(fromfile, line) ) {
            try {
                scores.push_back( std::stoi(line) );
            } catch ( exception& e ) {
                printf("line = \" %s \" is not a numbers. Error: %s", line.c_str(), e.what() );
            }
        }
        fromfile.close();
    }
    
    ofstream tofile ("/Users/benjurenka/Library/Developer/Xcode/DerivedData/Graphics_Example-fcszsdjyxjkgjsepbppfaaiqevas/Build/Products/Debug/highscore.txt");

    if( tofile.is_open() ) {
        std::sort(scores.begin(),scores.end(), std::greater<int>());
        for(int e: scores){
            tofile << e << "\n";
        }
        tofile.close();
    } else {
        std::cout << "unable to open file";
    }
    SDL_SetRenderDrawColor(renderer, 135, 206, 235, 255);
    SDL_RenderFillRect(renderer, &sky);
    setFont("text.ttf", 45);
    renderText("HIGH SCORES", 45, 20, 5, nullptr, 0, nullptr, SDL_FLIP_NONE, 224, 220, 220);
    setFont("text.ttf", 30);
    renderText(score_str, 30, WINDOW_WIDTH - 60, 10, nullptr, 0, nullptr, SDL_FLIP_NONE, 79, 27, 16);
   
    int x = 40, y = 0, z = 30;
    for( int i = 0; i < 24; ++i ) {
        std::string s = std::to_string( scores.at(i) );
        renderText(std::to_string(i + 1) + ":", 30 ,x    , 50 + y, nullptr, 0, nullptr, SDL_FLIP_NONE,  0,  0,  0);
        renderText(s                          , 30 ,x + z, 50 + y, nullptr, 0, nullptr, SDL_FLIP_NONE, 224, 20, 200);
        y += 30;
        if( i == 7 || i == 15 ) {
            x += 120;
            y = 0;
            z *= 1.2;
        }
    }
    
    //render daisy
    hazard_textures.at(0).render(425, 100, &hazard_frames[0], renderer);
    
    SDL_RenderPresent(renderer);
    while(stay){
    while( SDL_PollEvent(&Event) ) {
         SDL_RenderClear(renderer);
         if(Event.type == SDL_KEYDOWN ){
             if(Event.key.keysym.sym == SDLK_UP){
                 stay = false;
             }
         } else if(Event.type == SDL_QUIT){
             stay = false;
             Control::Running = false;
         }
     }
    }
    score_str = "";
    score = 0;
    lives = 3;
}
