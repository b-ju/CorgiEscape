#include "Control.h"

//***************  Control  ***************
//********* Default Constructor **********
Control::Control() {
    Running = true;
}

int Control::getWindowH(){
       return WINDOW_HEIGHT;
}
int Control::getWindowW(){
        return WINDOW_WIDTH;
}

// ******************** Exexute ********************
// *************************************************
int Control::OnExecute() {
    if(OnInit() == false || loadMedia() == false) {
        return -1;
    }
// Initialize local variables - corgi: collision object, counts for landscapes, random number for hazards, grass rects
      //object that contains and moves corgi collision rects

    for( int i = 0; i < NUMHAZ; i++){
        Hazard h(i, WINDOW_WIDTH);
        hazardVec.push_back(h);
    }
    
    for( int i = 0; i < NUMPLANTS; i++){
        Plant* p = new Plant(i, SPEED, WINDOW_WIDTH);
        plantVec.push_back(p);
    }
        
    orderOfPlants = make_normal_random(100, (std::uint_fast32_t) time(0), NUMPLANTS);
    orderOfHazards = make_normal_random(100, (std::uint_fast32_t) time(0), NUMHAZ);
    rand = make_normal_random(5000, (std::uint_fast32_t) time(0) , 100);
  
//*************GAME LOOP**************
//***********************************
    while(Running) {
        //check for events, grab events waiting in queue
        while( SDL_PollEvent(&Event) ) {
            OnEvent( &Event );
        }
      //*********** Start Screen **************
          if(startScreen){
              displayStartScreen();
              startScreen = false;
              music.playMusic();
              setFont("text.ttf", 30);
              hazardVec.at(1).setXLoc(510);
              hazardVec.at(1).setOnScreen(true);
            }
        SDL_RenderClear( renderer );
    //********* Render Scenery *******
        renderScenery();
    //********* Render Corgi ***********
    // move corgi texture and corgi collision boxes
        if(jump == true){
                Jump(jump_count, height, corgi);
        } else {
                Walk(walk_count, height);
        }
       // corgi.render(renderer);
    // ********** Render Frame Count **********
        
        score_str.clear();
        score_str = std::to_string(score);
        renderText(score_str, 30, WINDOW_WIDTH - 60, 10, nullptr, 0, nullptr, SDL_FLIP_NONE, 79, 27, 16);
        if( frame_count % 10 == 0){
            printf("frames_btw: %d , frame_count: %d\n",frames_between_haz,frame_count);
        }
    //*********** SEND HAZARD ACROSS SCREEN ********************
        if( (frame_count  > ( frames_between_haz + 50 ) ) ){
            if( rand.at(frame_count % rand.size()) > 85 && frame_count > 120  ){
                hazardIndex = orderOfHazards.at(nextHazard % orderOfHazards.size());
                printf("hazard index: %d ",hazardIndex);
                nextHazard++;
                frames_between_haz = frame_count;
                if(hazardVec.at(hazardIndex).getOnScreen() == false){
                    hazardVec.at(hazardIndex).setOnScreen(true);
                }
            }
        }
        // for every hazard check if it is on screen. Move hazard. Check for Collision
        for( Hazard h: hazardVec) {
            if( h.getOnScreen() ) {
                if(h.getHazardType() == 2){ // bird
                    sendHazard(2, flycount);
                } else { //other hazards ( daisy/poo/hoop )
                    sendHazard(h.getHazardType());
                }
                //h.render(renderer); //for testing
                if(  corgi.checkCollision(h.getColliders()) ) {
                    resetLevel();
                }
            }
        }
        //********** Render Lives *******************
        for(int i = 0; i < lives; ++i) {
            lifeTex.renderResize(lifeLoc, -8, renderer, 90, 90, 0, SDL_FLIP_NONE, nullptr, &life_frame);
            lifeLoc += 50;
        }
        lifeLoc = 369;
   //increase frame count/ present changes
        frame_count++;
        score++;
        SDL_Delay(25);
        SDL_RenderPresent(renderer);

        //************END RUNNING
    }
    OnCleanup();
    return 0;
}

// ****************** main *************************
// *************************************************
int main(int argc, char* argv[]) {
    Control game;
    return  game.OnExecute();
}
