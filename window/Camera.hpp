class Camera
{
public:

Camera();
~Camera();

void configure(const CameraProperties &CameraProperties, const SDL_Rect & viewportRect, const WorldProperties & worldProperties);

bool isViewableArea(const PointInt & pointInt);
void move(const PointDouble & pointDouble);
void setZoomFactor(const double & zoomFactorAdjustment);

const SDL_Rect & getRect();

private:

CameraProperties mCameraProperties;

SDL_Rect mCamera;
double mZoomFactor;

int mWorldPixelHeight;
int mWorldPixeWidth;
int mTextureSize;
};
