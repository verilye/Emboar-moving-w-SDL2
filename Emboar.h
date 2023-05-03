#ifndef EMBOAR
#define EMBOAR

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
// #include "Spritesheet.h"

class Emboar{

public:
    Emboar();
    ~Emboar() = default;

    void update(double delta_time);
    void draw(SDL_Surface *window_surface);

private:
    
    SDL_Surface *m_image;
    SDL_Rect     m_position;
    double       m_x;
    double       m_y;
};

#endif