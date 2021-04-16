//
//  Music.hpp
//  Graphics Example
//
//  Created by ben jurenka on 12/28/20.
//  Copyright © 2020 ben jurenka. All rights reserved.
//

#ifndef Music_hpp
#define Music_hpp
//
//  main.cpp
//  testMixer
//
//  Created by ben jurenka on 12/24/20.
//  Copyright © 2020 ben jurenka. All rights reserved.
//

//Using SDL, SDL_image, SDL_mixer, standard IO, and strings
#include <SDL.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <string>

class Music{
private:

    Mix_Music *music = NULL;
    Mix_Chunk *sound = NULL;
    bool isChunk;
    
public:
    
    Music();

    void setMusicPath(const char *path );
    
    void setChunkPath( const char *path);

    static int initMusic();

    void playMusic();
          
    void closeMusic();

    void pauseMusic();

    void unpauseMusic();
};
#endif /* Music_hpp */
