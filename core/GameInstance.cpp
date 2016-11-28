#include "include/global.hpp"

GameInstance::GameInstance()
{
    mGameInstanceProperties = new GameInstanceProperties();
    mWindowManager = new WindowManager(*mGameInstanceProperties);
    mInputEventTypeHandler = new InputEventTypeHandler();

    mRunning = false;

    const std::vector<SDL_EventType> & registeredSDLTypeEvents = mGameInstanceProperties->getRegisteredSDLTypeEvents();
    for (size_t i = 0; i < registeredSDLTypeEvents.size(); i++)
    {
        mInputEventTypeHandler->registerObserver(registeredSDLTypeEvents[i], this);
    }
}

GameInstance::~GameInstance()
{

}

void GameInstance::inputEventTypeCallback(SDL_EventType sdlEventType)
{
    if (sdlEventType == SDL_QUIT)
    {
        mRunning = false;
    }
    else if (sdlEventType == SDL_WINDOWEVENT)
    {
        SDL_Log("GameInstance::inputEventTypeCallback -- Window Changed! \n");
    }
    else
    {
        // unhandled / unregistered
    }
}

void GameInstance::run()
{
    mRunning = true;

    while ( mRunning )
    {
        mInputEventTypeHandler->pollEventQueue();
    }
}
