class Camera : public ScrollEventObserver, public ZoomEventObserver
{
public:

static Camera& Instance()
{
    static Camera instance;

    return instance;
}


void configure(const CameraProperties & cameraProperties);

void updateSize(const SDL_Rect & viewportRect);
void registerObserver(CameraObserver *CameraObserver);

bool isViewableArea(const SDL_Rect & rect);
void move(const PointDouble & pointDouble);
void setZoomFactor(const double & zoomFactorAdjustment);

void scrollEventCallback(SDL_Event scrollEvent);
void zoomEventCallback(const double & zoomAdjustment);

const SDL_Rect & getRect();
const double & getZoomFactor();

protected:

Camera();
Camera(const Camera&);
Camera& operator=(const Camera&);
~Camera();

private:

void dispatchZoomFactorUpdate();

CameraProperties mCameraProperties;

SDL_Rect mCamera;
double mZoomFactor;

int mTextureSize;

std::vector<CameraObserver *> mObservers;

};
