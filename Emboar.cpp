#include "Emboar.h"

Emboar::Emboar(){

    m_image = IMG_Load("Pacman.png");

    m_position.x = 0;
    m_position.y = 0;
    m_position.w = 22;
    m_position.h = 43;

    m_x = 0.0;
    m_y = 0.0;

}

void Emboar::update(double delta_time){
    m_x = m_x + (5.0 * delta_time);
    m_position.x = m_x;
}

void Emboar::draw(SDL_Surface *window_surface){

    SDL_BlitSurface(m_image, nullptr, window_surface, &m_position);
}