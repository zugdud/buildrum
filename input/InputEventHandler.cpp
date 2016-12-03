#include "include/global.hpp"

InputEventHandler::InputEventHandler()
{

}

InputEventHandler::~InputEventHandler()
{

}

void InputEventHandler::registerObserver(InputEventObserver *observer)
{
    mObservers.push_back(observer);
}

void InputEventHandler::pollEventQueue()
{
    SDL_Event sdlEvent;

    while ( SDL_PollEvent(&sdlEvent) != 0 )
    {
        InputEvent inputEvent = { sdlEvent };
        for (size_t i = 0; i < mObservers.size(); i++)
        {
            mObservers[i]->inputEventCallback(inputEvent);
        }
    }
}
