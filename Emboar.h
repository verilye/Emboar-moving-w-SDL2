#ifndef EMBOAR
#define EMBOAR

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Spritesheet.h"

class Emboar
{

public:
    Emboar();
    ~Emboar() = default;

    void update(double delta_time);
    void draw(SDL_Surface *window_surface);
    void handle_events(SDL_Event const &event);

    enum class Direction
    {
        NONE,
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    int const SPRITESHEET_UP = 3;
    int const SPRITESHEET_DOWN = 0;
    int const SPRITESHEET_LEFT = 1;
    int const SPRITESHEET_RIGHT = 2;

    

private:

    int m_spritesheet_column;

    Direction m_direction;
    Spritesheet *m_spritesheet;
    SDL_Rect m_position;
    double m_x;
    double m_y;
};

#endif