#ifndef SDL_CONFIG
#define SDL_CONFIG

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "Emboar.h"


class Application{

    public:

    Application();
    ~Application();


    void loop();
    void update(double delta_time);
    void draw();
    
    private:
    
    SDL_Window  *m_window;
    SDL_Surface *m_window_surface;
    SDL_Event    m_window_event;



};

#endif