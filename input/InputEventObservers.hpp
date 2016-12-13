class QuitEventObserver
{
public:

virtual void quitEventCallback() = 0;

};

class PointEventObserver
{
public:

virtual void pointEventCallback(PointInt pointInt) = 0;
virtual const std::string & getId() = 0;

};

class ScrollEventObserver
{
public:

virtual void scrollEventCallback(const PointInt & pointMovement) = 0;

};

class ZoomEventObserver
{
public:

virtual void zoomEventCallback(const double & zoomAdjustment) = 0;

};
