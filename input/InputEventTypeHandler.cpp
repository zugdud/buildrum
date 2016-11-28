#include "config/include.h"

InputEventTypeHandler::InputEventTypeHandler()
{

}

InputEventTypeHandler::~InputEventTypeHandler()
{

}

void InputEventTypeHandler::register (SDL_EventType sdlEventType, Observer * observer)
{
    mObservers[sdlEventType] = observer;
}

void InputEventTypeHandler::pollEventQueue()
{
    SDL_Event inputEvent;

    while ( SDL_PollEvent(&inputEvent) != 0 )
    {
        if ( mObservers.count(inputEvent.type) == 1)
        {
            mObservers[inputEvent.type]->inputEventTypeCallback(inputEvent.type);
        }
    }
}
