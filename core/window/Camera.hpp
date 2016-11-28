class Camera
{
public:

Camera(const CameraProperties &CameraProperties, const WindowProperties &windowProperties);
~Camera();

private:

setCamera(const WindowProperties &windowProperties);

CameraProperties mCameraProperties;
SDL_Rect mCamera;

};
