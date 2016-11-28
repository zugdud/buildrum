#include "include/global.hpp"

GameInstance::GameInstance()
{
    mGameInstanceProperties = new GameInstanceProperties();
    mWindowManager = new WindowManager(*mGameInstanceProperties);
    mRunning = false;
}

GameInstance::~GameInstance()
{

}

void GameInstance::inputEventTypeCallback(SDL_EventType sdlEventType)
{
    switch (sdlEventType)
    {
        case SDL_QUIT: mRunning = false; break;
        case SDL_WindowEvent:  SDL_Log("GameInstance::inputEventTypeCallback -- Window Changed! \n"); break;
    }
}

void GameInstance::run()
{
    mRunning = true;

    while ( mRunning )
    {
    }
}
