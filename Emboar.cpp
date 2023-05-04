#include "Emboar.h"

Emboar::Emboar()
{

    m_spritesheet = new Spritesheet("Emboar.png", 4, 6);

    m_position.x = 0;
    m_position.y = 0;
    m_position.w = 22;
    m_position.h = 43;

    m_x = 0.0;
    m_y = 0.0; 

    m_spritesheet->select_sprite(4,0);
}

void Emboar::update(double delta_time)
{
   switch(m_direction)
    {
        case Direction::NONE:
            m_x += 0.0;
            m_y += 0.0;
            m_spritesheet->select_sprite(0,0);
            break;
        case Direction::UP:
            m_y = m_y - (50.0 * delta_time);
            m_spritesheet->select_sprite(m_spritesheet_column, SPRITESHEET_UP);
            break;
        case Direction::DOWN:
            m_y = m_y + (50.0 * delta_time);
            m_spritesheet->select_sprite(m_spritesheet_column, SPRITESHEET_DOWN);
            break;
        case Direction::LEFT:
            m_x = m_x - (50.0 * delta_time);
            m_spritesheet->select_sprite(m_spritesheet_column, SPRITESHEET_LEFT);
            break;
        case Direction::RIGHT:
            m_x = m_x + (50.0 * delta_time);
            m_spritesheet->select_sprite(m_spritesheet_column, SPRITESHEET_RIGHT);
            break;
    }

    m_position.x = m_x;
    m_position.y = m_y;

    m_spritesheet_column++;

    if(m_spritesheet_column > 2){
        m_spritesheet_column = 0;
    }
}

void Emboar::draw(SDL_Surface *window_surface)
{

    m_spritesheet->draw_selected_sprite(window_surface, &m_position);
}

void Emboar::handle_events(SDL_Event const &event)
{
    switch (event.type)
    {
    case SDL_KEYDOWN:
        Uint8 const *keys = SDL_GetKeyboardState(nullptr);

        if (keys[SDL_SCANCODE_W] == 1)
            m_direction = Direction::UP;
        else if (keys[SDL_SCANCODE_S] == 1)
            m_direction = Direction::DOWN;
        else if (keys[SDL_SCANCODE_A] == 1)
            m_direction = Direction::LEFT;
        else if (keys[SDL_SCANCODE_D] == 1)
            m_direction = Direction::RIGHT;
        break;
    }
}