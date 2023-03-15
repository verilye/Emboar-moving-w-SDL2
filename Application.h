#ifndef SDL_CONFIG
#define SDL_CONFIG

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>


class Application{

    public:

    Application();
    ~Application();

    void update();
    void draw();
    
    private:
    SDL_Window  *m_window;
    SDL_Surface *m_window_surface;
    SDL_Event    m_window_event;



};

#endif