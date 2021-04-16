
#include <iostream>
#include <SDL2/SDL.h>

     const static int WINDOW_HEIGHT = 300;
     const static int WINDOW_WIDTH = 600;

    SDL_Window *window;
     SDL_Renderer *renderer;

using namespace std;

bool OnInit(){
  //Initialization flag
  bool success = true;

  //Initialize SDL
  if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ) {
      printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
      success = false;
  }  else {
      //Set texture filtering to linear
      if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) ) {
          printf( "Warning: Linear texture filtering not enabled!" );
      }

      //Create window
      window = SDL_CreateWindow( "Corgi Jump", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE  );
     
      if( window == NULL )  {
          printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
          success = false;
      } else {
          //Create renderer for window
          renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
      
          if( renderer == NULL ) {
              printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
              success = false;
          }
      }
  }

  return success;
}

int main(int argc, char * argv[]) {
   
    OnInit();
    SDL_RenderPresent(renderer);
    SDL_Delay(2000);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return 0;
}
