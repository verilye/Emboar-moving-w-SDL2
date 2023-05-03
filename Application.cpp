#include "Application.h"

Application::Application(){

    m_window = SDL_CreateWindow("SDL2 Window",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          1000, 800,
                                          0);

    if(!m_window)
    {
        std::cout << "Failed to create window\n";
        return;
    }

    m_window_surface = SDL_GetWindowSurface(m_window);

    if(!m_window_surface)
    {
        std::cout << "Failed to get the surface from the window\n";
        std::cout << "SDL2 Error: "<< SDL_GetError()<<"\n";
        return;
    }

    m_image = load_surface("Pacman.png");

};


Application::~Application()
{
    // Typical C++ memory cleanup

    SDL_FreeSurface(m_window_surface);
    SDL_DestroyWindow(m_window);
}

void Application::loop(){

}

void Application::update(){

    bool keep_window_open = true;
    while(keep_window_open)
    {
        SDL_Event e;
        while(SDL_PollEvent(&e) > 0)
        {
            switch(e.type)
            {
                case SDL_QUIT:
                    keep_window_open = false;
                    break;
            }
            //     SDL_BlitSurface(optimisedSurface, NULL, m_window_surface, NULL);
            //     SDL_UpdateWindowSurface(window);
            draw();
        }
    }


}

void Application::draw(){

    // SDL_FillRect(m_window_surface, nullptr, SDL_MapRGB(m_window_surface ->format, 0,0,0));

    // m_emboar.draw(m_window_surface);

    SDL_BlitSurface(m_image, NULL, m_window_surface, NULL);

    SDL_UpdateWindowSurface(m_window);

}

SDL_Surface * Application::load_surface(char const *path){

    SDL_Surface* optimisedSurface = NULL;
    SDL_Surface* image = IMG_Load(path);

    if(!image)
    {
        std::cout << "Failed to load image\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return NULL;
    }else{

        optimisedSurface = SDL_ConvertSurface(image, m_window_surface->format, 0);

        if(optimisedSurface == NULL){
            printf ("Unable to optimise image! SDL Error: ", SDL_GetError());
        }

        SDL_FreeSurface(image);
    }

    return optimisedSurface;
}