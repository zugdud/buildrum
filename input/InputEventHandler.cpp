#include "include/global.hpp"

InputEventHandler::InputEventHandler()
{

}

InputEventHandler::~InputEventHandler()
{

}

void InputEventHandler::registerTouchEventObserver(TouchEventObserver *touchEventObserver)
{
    mTouchEventObserver.push_back(touchEventObserver);
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
        // touch event
        if (sdlEvent.type == SDL_FINGERDOWN)
        {
            for (size_t i = 0; i < mQuitEventObservers.size(); i++)
            {
                mTouchEventObserver[i]->touchEventCallback(sdlEvent);
            }
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
//
// void InputEventHandler::handleTouchEvents(SDL_EventType & touchEvent)
// {
//     // Touch down
//     if ( touchEvent == SDL_FINGERDOWN )
//     {
//         // down
//         dispatchEvent(SDL_Event sdlEvent)
//         mCursor->setMomentum(0.0, 0.0);
//         mBuildMenu->isMenuArea(e.tfinger.dx, e.tfinger.dy);
//         mCursor->setPosition(e.tfinger.dx, e.tfinger.dy);
//     }
//     // // Touch motion
//     // if ( e.type == SDL_FINGERMOTION )
//     // {
//     //     int scaleFactor = G_FINGERINPUT_SCALINGFACTOR;
//     //     double velX = -1 * (e.tfinger.dx * scaleFactor);
//     //     double velY = -1 * (e.tfinger.dy * scaleFactor);
//     //     mCursor->setMomentum(velX, velY);
//     // }
//     // // Touch release
//     // else if ( e.type == SDL_FINGERUP )
//     // {
//     //     mCursor->setPosition(-1, -1);
//     // }
//     // // Multi touch gesture
//     // else if ( e.type == SDL_MULTIGESTURE )
//     // {
//     //     // Rotation detected
//     //     // if ( fabs(e.mgesture.dTheta) > 3.14 / 180.0 )
//     //     // {
//     //     //     // rotation
//     //     // }
//     //     // Pinch detected
//     //     if ( fabs(e.mgesture.dDist) > 0.002 )
//     //     {
//     //         // Pinch
//     //         int scaleFactor = 10;
//     //         setCameraZoom(e.mgesture.dDist * scaleFactor);
//     //     }
//     // }
// }
