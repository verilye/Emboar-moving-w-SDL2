#include "Spritesheet.h"

Spritesheet::Spritesheet(char const *path, int row, int column)
{
    m_spritesheet_image = IMG_Load(path);

    m_spritesheet_image = scale(m_spritesheet_image);

    m_clip.w = m_spritesheet_image->w / column;
    m_clip.h = m_spritesheet_image->h / row;

}

Spritesheet::~Spritesheet()
{
    SDL_FreeSurface(m_spritesheet_image);
}   

void Spritesheet::select_sprite(int x, int y)
{
    m_clip.x = x * m_clip.w;
    m_clip.y = y * m_clip.h;
}

void Spritesheet::draw_selected_sprite(SDL_Surface *window_surface, SDL_Rect *position)
{

    SDL_BlitSurface(m_spritesheet_image, &m_clip, window_surface, position);
}

SDL_Surface * Spritesheet::scale(SDL_Surface* surface){

    SDL_Surface * scaledSurface = SDL_CreateRGBSurface(
        0,
        surface->w / 4,
        surface->h / 4,
        surface->format->BitsPerPixel,
        surface->format->Rmask,
        surface->format->Gmask,
        surface->format->Bmask,
        surface->format->Amask
    );

    SDL_Rect srcRect = {0,0,surface->w, surface->h};
    SDL_Rect destRect = {0,0,scaledSurface->w, scaledSurface->h };

    SDL_BlitScaled(surface, &srcRect, scaledSurface, &destRect);

    // SDL_Texture* texture  = SDL_CreateTextureFromSurface(renderer, scaledSurface)

    return scaledSurface;
};
