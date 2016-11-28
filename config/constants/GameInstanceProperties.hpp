class GameInstanceProperties
{
public:

GameInstanceProperties();
~GameInstanceProperties();

const std::vector<ViewportProperties> & getViewportProperties();
const WindowProperties & getWindowProperties();

private:

void setViewports();
void setWindowProfiles();

std::vector<ViewportProperties> mViewportProperties;
std::map<std::string, WindowProperties> mWindowProperties; // profileId->Window

};
