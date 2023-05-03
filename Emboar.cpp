#include "Emboar.h"

Emboar::Emboar(){

    m_image = IMG_Load("Emboar.png");

    m_position.x = 0;
    m_position.y = 0;
    m_position.w = 44;
    m_position.h = 43;

    m_x = 0.0;
    m_y = 0.0;

}

void Emboar::update(double delta_time){
    m_x = m_x + (5.0 * delta_time);
    m_position.x = m_x;
}

void Emboar::draw(SDL_Surface *window_surface){

    SDL_Surface* optimisedSurface = SDL_ConvertSurface(m_image, window_surface->format, 0);

    if(!optimisedSurface){
        printf( "Unable to optimize image! SDL Error:", SDL_GetError() );
    }

    SDL_BlitSurface(optimisedSurface, nullptr, window_surface, &m_position);
}