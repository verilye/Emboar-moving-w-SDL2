#ifndef SPRITESHEET
#define SPRITESHEET



// https://dev.to/noah11012/using-sdl2-spritesheets-46h5

// Tutorial for writing a sprite sheet to screen

#include "SDL_config.h"

class Spritesheet
{

    public:
        Spritesheet(char const *path, int row, int column);
        ~Spritesheet();

        void select_sprite(int x, int y);
        void draw_selected_sprite(SDL_Surface *window_surface, SDL_Rect *position);

    private:
        SDL_Rect     m_clip;
        SDL_Surface *m_spritesheet_image;
};

#endif