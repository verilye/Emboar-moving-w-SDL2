#include "Application.h"

Application::Application(){

    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Failed to initialize the SDL2 library\n";
        return;
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
        return;
    }

    m_window_surface = SDL_GetWindowSurface(window);

    if(!m_window_surface)
    {
        std::cout << "Failed to get the surface from the window\n";
        std::cout << "SDL2 Error: "<< SDL_GetError()<<"\n";
        return;
    }

};


Application::~Application()
{
    // Typical C++ memory cleanup

    SDL_FreeSurface(m_window_surface);
    SDL_DestroyWindow(m_window);
}

void Application::loop(){

    SDL_Surface* emboar = IMG_Load("Emboar.png");

    SDL_Surface* optimisedSurface = SDL_ConvertSurface(emboar, m_window_surface->format, 0);

    if(!optimisedSurface)
    {
        std::cout << "Failed to load image\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return;
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

            

            SDL_BlitSurface(optimisedSurface, nullptr, m_window_surface, nullptr);

            // update(1.0/60);
            draw();
        }
    }
}

// void Application::update(double delta_time){

//     // This block keeps the window open and waits for a close window event
//     // Also draws the updated surface to window

//     m_image_position.x = m_image_position.x + (1 * delta_time);

// }

void Application::draw(){

    // SDL_FillRect(m_window_surface, nullptr, SDL_MapRGB(m_window_surface ->format, 0,0,0));

    // m_emboar.draw(m_window_surface);

    SDL_UpdateWindowSurface(m_window);

}

SDL_Surface *load_surface(char const *path){
    
    SDL_Surface *image_surface = SDL_LoadBMP(path);

    if(!image_surface){
        return 0;
    }

    return image_surface;
}