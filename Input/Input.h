#ifndef INPUT
#define INPUT

#include <SDL2/SDL.h>
#include "KeyboardListener.h"

// Im attempting to use the 'Observer' pattern here
// Listen for inputs, add them to a data structure
// then deal with them in a pipeline

class Input{

public:

    Input();
    // Add a pointer to a list
    void addListener(KeyboardListener* pListener);


};

#endif