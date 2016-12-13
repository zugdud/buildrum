class CameraObserver
{
public:

virtual void positionUpdate(const SDL_Rect & cameraRect) = 0;
virtual void zoomFactorUpdate(const double & zoomFactor) = 0;

};
