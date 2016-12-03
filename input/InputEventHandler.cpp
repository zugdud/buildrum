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
            PointInt pointInt = { 0, 0 };
            if (SDL_FINGERDOWN)
            {
                pointInt.x = sdlEvent.tfinger.dx;
                pointInt.y = sdlEvent.tfinger.dy;
            }
            else if (SDL_MOUSEBUTTONDOWN)
            {
                pointInt.x = sdlEvent.button.x;
                pointInt.y = sdlEvent.button.y;
            }

            for (size_t i = 0; i < mPointEventObserver.size(); i++)
            {
                mPointEventObserver[i]->pointEventCallback(pointInt);
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
// void InputEventHandler::handleMouseEvents(SDL_Event & e)
// {
//     switch (e.type)
//     {
//         case SDL_MOUSEBUTTONDOWN: {
//             if (mBuildMenu->isMenuArea(e.button.x, e.button.y))
//             {
//                 Button *button = mBuildMenu->selectedButton(e.button.x, e.button.y);
//                 mPlayer->setCurrentAction(button->getAction());
//             }
//             else
//             {
//                 Action *action = mPlayer->getCurrentAction();
//                 action->performAction(mCursor->getHighlightedTileId());
//             }
//         } break;
//         case SDL_MOUSEMOTION: {
//             mCursor->setPosition(e.motion.x, e.motion.y);
//             mCursor->setEdge();
//         } break;
//     }
// }

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
