#include "SDL_config.h"

void openNewWindow(){

    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Failed to initialize the SDL2 library\n";
        return;
    }

    SDL_Window *window = SDL_CreateWindow("SDL2 Window",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          680, 480,
                                          0);

    if(!window)
    {
        std::cout << "Failed to create window\n";
        return;
    }

    SDL_Surface *window_surface = SDL_GetWindowSurface(window);

    if(!window_surface)
    {
        std::cout << "Failed to get the surface from the window\n";
        std::cout << "SDL2 Error: "<< SDL_GetError()<<"\n";
        return;
    }


    SDL_Surface* optimizedSurface = NULL;
    SDL_Surface* image = IMG_Load("Emboar.png");

    if(!image)
    {
        std::cout<<"Failed to load image\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return;
    }else
    {

        optimizedSurface = SDL_ConvertSurface(image, window_surface->format, 0);

        if( optimizedSurface == NULL )
        {
            printf( "Unable to optimize image! SDL Error:", SDL_GetError() );
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( image );

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

            SDL_BlitSurface(optimizedSurface, NULL, window_surface, NULL);
            SDL_UpdateWindowSurface(window);
        }
    }

    return;

};