#ifndef SPRITESHEET
#define SPRITESHEET

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Spritesheet
{

public:
    Spritesheet(char const *path, int row, int column);
    ~Spritesheet();

    void select_sprite(int x, int y);
    void draw_selected_sprite(SDL_Surface *window_surface, SDL_Rect *position);

private:
    SDL_Rect m_clip;
    SDL_Surface *m_spritesheet_image;
};

#endif