class GameInstanceProperties
{
public:

GameInstanceProperties();
~GameInstanceProperties();

private:

void setViewports();
void setWindowProfiles();
void setCamera();

std::vector<ViewportProperties> mViewportProperties;
std::map<std::string, WindowProperties> mWindowProperties; // profileId->Window
CameraProperties mCameraProperties;

};
