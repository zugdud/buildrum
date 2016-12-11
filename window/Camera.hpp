class Camera : public ScrollEventObserver, public ZoomEventObserver
{
public:

static Camera& Instance()
{
    static Camera instance;

    return instance;
}



void configure(const Viewport & viewport, const WorldProperties & worldProperties);

bool isViewableArea(const SDL_Rect & rect);
void move(const PointDouble & pointDouble);
void setZoomFactor(const double & zoomFactorAdjustment);

void scrollEventCallback(SDL_Event scrollEvent);
void zoomEventCallback(SDL_Event zoomEvent);

const SDL_Rect & getRect();

protected:

Camera();
Camera(const Camera&);
Camera& operator=(const Camera&);
~Camera();

private:

CameraProperties mCameraProperties;

SDL_Rect mCamera;
double mZoomFactor;

int mWorldPixelHeight;
int mWorldPixeWidth;

int mTextureSize;

};
