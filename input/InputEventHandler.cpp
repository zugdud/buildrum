#include "config/include.h"

InputEventHandler::InputEventHandler()
{

}

InputEventHandler::~InputEventHandler()
{

}

void InputEventHandler::pollEventQueue()
{
    SDL_Event e;

    while ( SDL_PollEvent(&e) != 0 )
    {
        // quit event
        if ( e.type == SDL_QUIT )
        {
            quit = true;
        }
        // keyboard events
        else if (e.type == SDL_KEYDOWN)
        {
            handleKeyboardEvents(e);
        }
        // unhandled events
        else
        {
            // unhandled
        }
    }
}

void InputEventHandler::handleKeyboardEvents(SDL_Event & event)
{
    switch ( event.key.keysym.sym )
    {
        // case SDLK_1: setCameraZoom(0.10); break;
    }
}
