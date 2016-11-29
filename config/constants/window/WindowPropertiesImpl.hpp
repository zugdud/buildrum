class WindowPropertiesImpl
{
public:

WindowPropertiesImpl();
~WindowPropertiesImpl();

void loadAll();

const std::vector<ViewportProperties> & getViewportProperties() const;
const WindowProperties & getWindowProperties();

private:

void setViewports();
void setWindowProfiles();

std::vector<ViewportProperties> mViewportProperties;
std::map<std::string, WindowProperties> mWindowProperties; // profileId->Window
std::vector<UIMenuProperties> mUIMenuProperties;

};
