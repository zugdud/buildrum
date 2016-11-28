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

std::vector<InputTypeEventProperties> mInputTypeEventProperties;
std::vector<InputKeyEventProperties> mInputKeyEventProperties;

std::map<std::string, InputPointEventProperties> mInputPointEventProperties; // pointEventId->Props, dynamic updates

std::vector<InputScrollEventProperties> mInputScrollEventProperties;

};
