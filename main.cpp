#include "Application.h"
#include "Input/Input.h"
#include <iostream>

// This game will run on an entity component system
// An entity is a thing in the game, components are attributes of the thing

int main(int, char **)
{

    Application app;

    app.loop();

    return 1;
}
