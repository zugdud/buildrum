class GameInstanceProperties
{
public:

GameInstanceProperties();
~GameInstanceProperties();

void loadAll();

const std::vector<ViewportProperties> & getViewportProperties() const;
const WindowProperties & getWindowProperties();
const std::vector<SDL_EventType> & getRegisteredSDLTypeEvents() const;

private:

void setViewports();
void setWindowProfiles();
void setRegisteredSDLTypeEvents();

std::vector<ViewportProperties> mViewportProperties;
std::map<std::string, WindowProperties> mWindowProperties; // profileId->Window
std::vector<UIMenuProperties> mUIMenuProperties;

std::vector<SDL_EventType> mRegisteredSDLTypeEvents;

};
