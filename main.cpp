#include "Application.h"
#include "Input/Input.h"
#include <iostream>

// Compile and build setup with CMAKe
// Setup in cmake
// https://code.visualstudio.com/docs/cpp/cmake-linux
// Go down to the bottom bar and select build in vscode
// Press f5 to run current version of project

// HELPFUL LINKS

// 2D game physics engine
// https://developer.ibm.com/tutorials/wa-build2dphysicsengine/ 

// Potentially use an already created game engine UI (NOT INGAME UI)
// https://github.com/ocornut/imgui 

// Scripting for faster implementation?? Lua, C#, python??

// This game will run on an entity component system
// An entity is a thing in the game, components are attributes of the thing

int main(int, char**){

    Application app;

    app.update();
    app.draw();

    //This gameloop is a single frame. Ill have to time it so that it runs at around 60fps
    // bool isRunning = true;
    // while(isRunning){

    //     // Take any input from user
    //     // Abstract it out using an interface
    //     Input();
    //     // Update the screen. This should continue even when no actions are being taken 
    //     Update();
    //     // Render these updates to screen
    //     Render();
    // }
    
    return 1;
}


