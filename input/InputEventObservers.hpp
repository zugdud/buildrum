class QuitEventObserver
{
public:

virtual void quitEventCallback() = 0;

};

class PointEventObserver
{
public:

virtual void pointEventCallback(PointInt pointInt) = 0;

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
