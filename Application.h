#ifndef SDL_CONFIG
#define SDL_CONFIG

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "Emboar.h"

class Application
{

public:
    Application();
    ~Application();

    void loop();
    void update(double delta_time);
    void draw();
    SDL_Surface *load_surface(char const *path);

private:

    double m_image_x;
    double m_image_y;

    SDL_Surface *m_image;
    SDL_Rect m_image_position;

    SDL_Window *m_window;
    SDL_Surface *m_window_surface;
    SDL_Event m_window_event;
};

#endif