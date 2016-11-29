#include "include/global.hpp"

InputEventTypeHandler::InputEventTypeHandler()
{

}

InputEventTypeHandler::~InputEventTypeHandler()
{

}

void InputEventTypeHandler::registerObserver(SDL_EventType sdlEventType, InputEventTypeObserver *observer)
{
    mObservers[sdlEventType] = observer;
}

void InputEventTypeHandler::pollEventQueue()
{
    SDL_Event inputEvent;

    while ( SDL_PollEvent(&inputEvent) != 0 )
    {
        SDL_EventType inputEventType = static_cast<SDL_EventType>(inputEvent.type);
        if ( mObservers.count(inputEventType) == 1)
        {
            mObservers[inputEventType]->inputEventTypeCallback(inputEventType);
        }
    }
}
