class QuitEventObserver
{
public:

virtual void quitEvent() = 0;

};

class TouchEventObserver
{
public:

virtual void touchEvent(SDL_TouchFingerEvent touchEvent) = 0;

};

class ScrollEventObserver
{
public:

virtual void scrollEvent(SDL_TouchFingerEvent scrollEvent) = 0;

};

class ZoomEventObserver
{
public:

virtual void zoomEvent(SDL_MultiGestureEvent zoomEvent) = 0;

};
