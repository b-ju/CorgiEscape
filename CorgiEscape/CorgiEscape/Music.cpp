//
//  Music.hpp
//  Graphics Example
//
//  Created by ben jurenka on 12/28/20.
//  Copyright © 2020 ben jurenka. All rights reserved.
//

//  main.cpp
//  testMixer
//
//  Created by ben jurenka on 12/24/20.
//  Copyright © 2020 ben jurenka. All rights reserved.
//

//Using SDL, SDL_image, SDL_mixer, standard IO, and strings
#include "Music.hpp"
Music::Music( ) {

}

void Music::setMusicPath( const char *path ){
    isChunk = false;
    music = Mix_LoadMUS(path);
}

void Music::setChunkPath( const char *path){
    isChunk = true;
    sound = Mix_LoadWAV(path);
}


int Music::initMusic(){
    if( SDL_Init( SDL_INIT_AUDIO ) < 0 )
       {
           printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
           return -1;
       }
    
    //Initialize SDL_mixer
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
        {
            printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
            return -1;
        }
    return 0;
   

}

void Music::playMusic(){
     //Load music
     if( music == NULL && sound == NULL){
         printf( "Failed to load music! SDL_mixer Error: %s\n", Mix_GetError() );
     }
    if(isChunk){
        Mix_PlayChannel(-1, sound, 0);
    } else {
        Mix_PlayMusic( music, -1 );
    }
}

void Music::closeMusic(){ 
    Mix_FreeMusic( music );
    Mix_FreeChunk( sound);
    music = NULL;
    sound = NULL;
}

void Music::pauseMusic(){
    //if music is playing
    if(Mix_PlayingMusic() == 1){
        Mix_PauseMusic();
    }
}

void Music::unpauseMusic(){
    //if music is paused
    if(Mix_PausedMusic() == 1){
        Mix_ResumeMusic();
    }
}


