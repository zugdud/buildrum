#include "include/global.hpp"

InputEventHandler::InputEventHandler()
{

}

InputEventHandler::~InputEventHandler()
{

}

void InputEventHandler::registerPointEventObserver(PointEventObserver *pointEventObserver)
{
    mPointEventObserver.push_back(pointEventObserver);
}

void InputEventHandler::registerQuitEventObserver(QuitEventObserver *quitEventObserver)
{
    mQuitEventObservers.push_back(quitEventObserver);
}

void InputEventHandler::pollEventQueue()
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

void InputEventHandler::dispatchPointEvent(const SDL_Event & sdlEvent)
{
    PointInt pointInt = { 0, 0 };

    switch (G_BUILD_PROFILE)
    {
        case LINUX_BUILD: {
            pointInt.x = sdlEvent.button.x;
            pointInt.y = sdlEvent.button.y;
        }; break;
        case MAC_BUILD: {
            pointInt.x = sdlEvent.button.x;
            pointInt.y = sdlEvent.button.y;
        }; break;
        case ANDROID_BUILD: {
            pointInt.x = sdlEvent.tfinger.dx;
            pointInt.y = sdlEvent.tfinger.dy;
        }; break;
    }

    for (size_t i = 0; i < mPointEventObserver.size(); i++)
    {
        mPointEventObserver[i]->pointEventCallback(pointInt);
    }
}
