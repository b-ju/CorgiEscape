
#ifndef _CONTROL_H_
    #define _CONTROL_H_
 
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <cstdlib>
#include <array>
#include <ctime>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "Hazard.h"
#include "Control.h"
#include "TextureW.h"
#include "Corgi.hpp"
#include "TextureW.h"
#include "Plant.hpp"
#include "Music.hpp"

class Control {
private:
    
    Corgi corgi;
    const static int WINDOW_HEIGHT = 300;
    const static int WINDOW_WIDTH = 600;
    const static int NUMHAZ = 4;
    const static int NUMPLANTS = 12;
    
    int lives = 3;
    int frame_count = 0;
    const static int FF_NUM = 100;
    const static int MF_NUM = 1316;
    const static int CF_NUM = 10;
    const static int PF_NUM = 10;
    const static int SPEED = 6;
    
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event Event;

    std::vector<int> orderOfPlants;
    std::vector<int> orderOfHazards;
    std::vector<Hazard> hazardVec;
    std::vector<Plant*> plantVec;
    std::vector<int> rand;
    
    bool Running;
    bool jump;
    int hazardIndex;
    int jump_count = 0;
    int fenceLoc = 0;
    int fence_hazard_loc = 465;
    int height = 135; // distance from top of screen
    int walk_count = 0;
    const int FROM_LEFT = 12;   // x cordinate for renderering corgo

    //Textures and recs for anything renderering to screen
    TextureW corgi_texture;
    SDL_Rect corgi_frames[ 4 ];
        
    std::vector<TextureW> hazard_textures;
    SDL_Rect hazard_frames[ 4 ];
    
    int flycount = 0;
    int frames_between_haz = 0;
    
    TextureW fence_texture;
    SDL_Rect fence_frame = {0,0,600,300};
    
    TextureW hoop_texture;
    SDL_Rect hoop_frame = {0, 0, 130, 200};
    SDL_Rect hoop_stand_frame = {130, 0, 70, 200};
    
    TextureW bird_texture;
    SDL_Rect bird_frames[4];
    
    TextureW mountain_texture;
    SDL_Rect mountain_frames[ MF_NUM ];
    
    SDL_Rect sky { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT };
    
    TextureW plant_texture;
    SDL_Rect plant_frames[ PF_NUM ];
    int plantIndex  = 0;
    
    TextureW ground_texture;
    SDL_Rect groundFrame = { 0, 0, 84, 74};
    int groundLoc = -40;
    
    TextureW lifeTex;
    SDL_Rect life_frame = { 0 , 0 , 400, 400};
    int lifeLoc = 369;
    
    int cloud_Xloc = 600, cloud_Yloc = 0;

    //Variables for text rendering
    TTF_Font *font;
    std::vector<SDL_Texture*> words;
    int text_Width = 0;
    int text_Height = 0;
    std::string frame_count_str = "";
    std::string score_str = "";
    int score = 0;
    void highscore ();

    Music music ;
    Music fartSound ;
    Music jumpSound ;
    
public:
 
    Control();
             
    int OnExecute();
    
    bool OnInit();
    
    void OnEvent(SDL_Event* Event);
    
    void OnLoop();
    
    void OnRender();
    
    void OnCleanup();
    
    bool loadLandscape(std::string path, SDL_Renderer* renderer, TextureW& tex, SDL_Rect* rect,  int num_frames, int pixels_from_top, int pixels_per_frame, int w, int h );
    
    bool loadSprites(std::string path, SDL_Renderer* renderer, TextureW& tex, SDL_Rect* clips);
    
    bool loadPic(std::string path, SDL_Renderer* renderer, TextureW& tex );

    void Jump(int& count, int& height, Corgi& c);
    
    void Walk(int& walk_count, int& height );
    
    bool renderText(std::string sentence, int font_size, int x, int y, SDL_Rect* clip,
                    double angle, SDL_Point* center, SDL_RendererFlip flip,
                    Uint8 r, Uint8 g, Uint8 b );
    
    bool setFont(std::string path, int font_size);
    
    static int getWindowH( );
            
    static int getWindowW( );
 
    void sendHazard( int type );
    
    void sendHazard(int type , int& flyCount); //method for bird hazard

    void resetLevel( );
    
    bool startScreen = true;
    
    void displayStartScreen( ); 
    
    void loadButton( bool highlight );
    
    void renderScenery();
    
    bool loadMedia( );
    
    std::vector<int> make_normal_random(std::size_t number, std::uint_fast32_t seed, int max);

    int nextHazard = 0;
 
      
};

 
#endif
