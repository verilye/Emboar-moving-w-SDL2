#include "Input.h"

void Input(){

    // SDL needs to used to access hardware events
    // Its a wrapper that allows for cross platform hardware access

    SDL_Event event;

    //TODO SDL POLL EVENT??

    while(SDL_PollEvent(&event)){
        switch(event.type){
            case SDL_KEYDOWN:
                if(event.key.keysym.sym == SDLK_SPACE){
                    // PLAYER ACTION
                    // SPACEBAR
                }
        }
    }

};