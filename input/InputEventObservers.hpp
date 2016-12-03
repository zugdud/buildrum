class QuitEventObserver
{
public:

virtual void quitEventCallback() = 0;

};

class TouchEventObserver
{
public:

virtual void touchEventCallback(SDL_Event touchEvent) = 0;

};

class ScrollEventObserver
{
public:

virtual void scrollEventCallback(SDL_Event scrollEvent) = 0;

};

class ZoomEventObserver
{
public:

virtual void zoomEventCallback(SDL_Event zoomEvent) = 0;

};
