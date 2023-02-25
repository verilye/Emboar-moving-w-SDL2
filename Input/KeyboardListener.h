#ifndef KEYBOARD_LISTENER
#define KEYBOARD_LISTENER

#include <SDL2/SDL.h>

// This class basically represents an instance
// of keyboard input

class KeyboardListener{

public:

    // This should be a record of a keyboard event

    void OnKeyEvent(const SDL_KeyboardEvent& evt);


};


#endif
