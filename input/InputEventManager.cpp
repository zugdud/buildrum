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

void InputEventManager::removePointEventObserver(const std::string & id)
{
    for (size_t i = 0; i < mPointEventObserver.size(); i++)
    {
        if (mPointEventObserver[i]->getId() == id)
        {
            SDL_Log("InputEventManager::removePointEventObserver -- removing observer id: %s \n", id.c_str());
            mPointEventObserver.erase(mPointEventObserver.begin() + i);
        }
    }
}

void InputEventManager::registerScrollEventObserver(ScrollEventObserver *scrollEventObserver)
{
    mScrollEventObservers.push_back(scrollEventObserver);

}
void InputEventManager::registerZoomEventObserver(ZoomEventObserver *zoomEventObserver)
{
    mZoomEventObservers.push_back(zoomEventObserver);
}

void InputEventManager::registerPointEventObserver(PointEventObserver *pointEventObserver)
{
    SDL_Log("InputEventManager::registerPointEventObserver -- registering observer id: %s \n", pointEventObserver->getId().c_str());
    mPointEventObserver.push_back(pointEventObserver);
}

void InputEventManager::registerQuitEventObserver(QuitEventObserver *quitEventObserver)
{
    mQuitEventObservers.push_back(quitEventObserver);
}

void InputEventManager::update()
{
    SDL_Event sdlEvent;

    while ( SDL_PollEvent(&sdlEvent) != 0 )
    {
        switch ( sdlEvent.type )
        {
            case SDL_FINGERDOWN: dispatchPointEvent(sdlEvent); break;
            case SDL_MOUSEBUTTONDOWN: dispatchPointEvent(sdlEvent); break;
            case SDL_MULTIGESTURE: handleMultiTouch(sdlEvent); break;
            case SDL_KEYDOWN:     handleKeyEvents(sdlEvent); break;
            case SDL_FINGERMOTION:     handleFingerMotion(sdlEvent); break;
            case SDL_QUIT:     dispatchQuitEvent(); break;
        }
    }

    // process momentum
    dispatchScrollEvent(mInputMomentum.decay());
}


void InputEventManager::handleKeyEvents(const SDL_Event & sdlEvent)
{
    switch ( sdlEvent.key.keysym.sym )
    {
        case SDLK_1: dispatchZoomEvent(0.2); break;
        case SDLK_2: dispatchZoomEvent(-0.2); break;
        case SDLK_UP: mInputMomentum.update(0, -20); break;
        case SDLK_DOWN: mInputMomentum.update(0, 20); break;
        case SDLK_LEFT: mInputMomentum.update(-20, 0); break;
        case SDLK_RIGHT: mInputMomentum.update(20, 0); break;
    }
}

void InputEventManager::handleFingerMotion(const SDL_Event & sdlEvent)
{
    int scaleFactor = 1000;
    int velX = -1 * (sdlEvent.tfinger.dx * scaleFactor);
    int velY = -1 * (sdlEvent.tfinger.dy * scaleFactor);

    mInputMomentum.update(velX, velY);
}

void InputEventManager::handleMultiTouch(const SDL_Event & sdlEvent)
{
    // if ( fabs(sdlEvent.mgesture.dDist) > 0.002 )
    // {
    int scaleFactor = 4;
    double zoomFactor = sdlEvent.mgesture.dDist * scaleFactor;

    dispatchZoomEvent(zoomFactor);
    // }
}

void InputEventManager::dispatchQuitEvent()
{
    for (size_t i = 0; i < mQuitEventObservers.size(); i++)
    {
        mQuitEventObservers[i]->quitEventCallback();
    }
}

void InputEventManager::dispatchScrollEvent(const PointInt & momentum)
{
    for (size_t i = 0; i < mScrollEventObservers.size(); i++)
    {
        mScrollEventObservers[i]->scrollEventCallback(momentum);
    }
}

void InputEventManager::dispatchZoomEvent(const double & zoomFactor)
{
    for (size_t i = 0; i < mZoomEventObservers.size(); i++)
    {
        mZoomEventObservers[i]->zoomEventCallback(zoomFactor);
    }
}

void InputEventManager::dispatchPointEvent(const SDL_Event & sdlEvent)
{
    PointInt pointInt = { 0, 0 };
    PointInt viewportOffset =  SceneManager::getInstance()->getViewportOffset(pointInt);

    pointInt.x = sdlEvent.button.x - viewportOffset.x;
    pointInt.y = sdlEvent.button.y - viewportOffset.y;

    // pointInt.x = sdlEvent.tfinger.dx;
    // pointInt.y = sdlEvent.tfinger.dy;

    SDL_Log("InputEventManager::dispatchPointEvent -- viewportOffset: [x: %d y: %d] adjustedEvent: [x: %d y: %d] \n",
            viewportOffset.x,
            viewportOffset.y,
            pointInt.x,
            pointInt.y);


    for (size_t i = 0; i < mPointEventObserver.size(); i++)
    {
        mPointEventObserver[i]->pointEventCallback(pointInt);
    }
}
