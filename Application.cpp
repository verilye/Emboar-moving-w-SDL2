#include "Application.h"

Application::Application()
{

    m_window = SDL_CreateWindow("SDL2 Window",
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                1920, 1080,
                                0);

    if (!m_window)
    {
        std::cout << "Failed to create window\n";
        return;
    }

    m_window_surface = SDL_GetWindowSurface(m_window);

    if (!m_window_surface)
    {
        std::cout << "Failed to get the surface from the window\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return;
    }

};

Application::~Application()
{
    // Typical C++ memory cleanup

    SDL_FreeSurface(m_window_surface);
    SDL_DestroyWindow(m_window);
}

void Application::loop()
{
    bool keep_window_open = true;
    while (keep_window_open)
    {
        while (SDL_PollEvent(&m_window_event) > 0)
        {

            m_emboar.handle_events(m_window_event);

            switch (m_window_event.type)
            {
            case SDL_QUIT:
                keep_window_open = false;
                break;
            }
        }

        update(1.0 / 60.0);
        draw();
    }
}

void Application::update(double delta_time)
{

    m_emboar.update(delta_time);
}

void Application::draw()
{

    SDL_FillRect(m_window_surface, nullptr, SDL_MapRGB(m_window_surface->format, 0, 0, 0));

    m_emboar.draw(m_window_surface);

    SDL_UpdateWindowSurface(m_window);
}

SDL_Surface *Application::load_surface(char const *path)
{

    SDL_Surface *optimisedSurface = NULL;
    SDL_Surface *image = IMG_Load(path);

    if (!image)
    {
        std::cout << "Failed to load image\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return NULL;
    }
    else
    {

        optimisedSurface = SDL_ConvertSurface(image, m_window_surface->format, 0);

        if (optimisedSurface == NULL)
        {
            printf("Unable to optimise image! SDL Error: ", SDL_GetError());
        }

        SDL_FreeSurface(image);
    }

    return optimisedSurface;
}