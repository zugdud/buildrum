#include "include/global.hpp"

InputEventManager *InputEventManager::mSingletonInstance = 0;

InputEventManager::InputEventManager()
{

}

InputEventManager::~InputEventManager()
{

}

InputEventManager * InputEventManager::getInstance()
{
    if (!mSingletonInstance)
    {
        mSingletonInstance = new InputEventManager;
    }
    return mSingletonInstance;
}

void InputEventManager::registerPointEventObserver(PointEventObserver *pointEventObserver)
{
    mPointEventObserver.push_back(pointEventObserver);
}

void InputEventManager::registerQuitEventObserver(QuitEventObserver *quitEventObserver)
{
    mQuitEventObservers.push_back(quitEventObserver);
}

void InputEventManager::pollEventQueue()
{
    SDL_Event sdlEvent;

    while ( SDL_PollEvent(&sdlEvent) != 0 )
    {
        // point event
        if (sdlEvent.type == SDL_FINGERDOWN || sdlEvent.type == SDL_MOUSEBUTTONDOWN)
        {
            dispatchPointEvent(sdlEvent);
        }
        // quit event
        else if (sdlEvent.type == SDL_QUIT)
        {
            for (size_t i = 0; i < mQuitEventObservers.size(); i++)
            {
                mQuitEventObservers[i]->quitEventCallback();
            }
        }
        else
        {
            // filtered
        }
    }
}

void InputEventManager::dispatchPointEvent(const SDL_Event & sdlEvent)
{
    PointInt pointInt = { 0, 0 };

    pointInt.x = sdlEvent.button.x;
    pointInt.y = sdlEvent.button.y;

    // pointInt.x = sdlEvent.tfinger.dx;
    // pointInt.y = sdlEvent.tfinger.dy;

    for (size_t i = 0; i < mPointEventObserver.size(); i++)
    {
        mPointEventObserver[i]->pointEventCallback(pointInt);
    }
}
