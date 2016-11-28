class Camera
{
public:

Camera(const CameraProperties &CameraProperties, const WindowProperties &windowProperties);
~Camera();

private:

CameraProperties mCameraProperties;

SDL_Rect mCamera;
double mZoomFactor;

int mWorldWidth;
int mWorldHeight;

};
