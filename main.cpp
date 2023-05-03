#include "Application.h"
#include "Input/Input.h"
#include <iostream>

// This game will run on an entity component system
// An entity is a thing in the game, components are attributes of the thing

int main(int, char**){

    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Failed to initialize the SDL2 library\n";
        return -1;
    }

    // Create a window with SDL2 (operating system neutral)

    SDL_Window *window = SDL_CreateWindow("SDL2 Window",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          1000, 800,
                                          0);

    if(!window)
    {
        std::cout << "Failed to create window\n";
        return -1;
    }

    SDL_Surface* m_window_surface = SDL_GetWindowSurface(window);

    if(!m_window_surface)
    {
        std::cout << "Failed to get the surface from the window\n";
        std::cout << "SDL2 Error: "<< SDL_GetError()<<"\n";
        return -1;
    }

    SDL_Surface* optimisedSurface = NULL;
    SDL_Surface* image = IMG_Load("Emboar.png");


    if(!image)
    {
        std::cout << "Failed to load image\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return -1;
    }else{

        optimisedSurface = SDL_ConvertSurface(image, m_window_surface->format, 0);

        if(optimisedSurface == NULL){
            printf ("Unable to optimise image! SDL Error: ", SDL_GetError());
        }

        SDL_FreeSurface(image);
    }

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

            

            SDL_BlitSurface(optimisedSurface, NULL, m_window_surface, NULL);
            SDL_UpdateWindowSurface(window);
        }
    }
    
    return 1;
}


