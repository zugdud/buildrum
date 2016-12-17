class Camera : public ScrollEventObserver, public ZoomEventObserver
{
public:

static Camera& Instance()
{
    static Camera instance;

    return instance;
}

void resetCamera();
void configure(const CameraProperties & cameraProperties);

void updateSize(const SDL_Rect & viewportRect);
void registerObserver(CameraObserver *CameraObserver);

bool isViewableArea(const SDL_Rect & rect);
void setPosition(const PointInt & pointMovement);
void setZoomFactor(const double & zoomFactorAdjustment);

void scrollEventCallback(const PointInt & pointMovement);
void zoomEventCallback(const double & zoomAdjustment);

const SDL_Rect & getRect();
const double & getZoomFactor();

protected:

Camera();
Camera(const Camera&);
Camera& operator=(const Camera&);
~Camera();

private:

void dispatchPositionUpdate();
void dispatchZoomFactorUpdate();

CameraProperties mCameraProperties;

SDL_Rect mCamera;
double mZoomFactor;

int mTextureSize;

std::vector<CameraObserver *> mObservers;

};
