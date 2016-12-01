class WindowPropertiesImpl
{
public:

WindowPropertiesImpl();
~WindowPropertiesImpl();

void loadAll();

const std::vector<ViewContextProperties> & getViewContextProperties() const;
const WindowProperties & getWindowProperties();

private:

void setViewContexts();
void setWindowProfiles();

std::vector<ViewContextProperties> mViewContextProperties;
std::map<std::string, WindowProperties> mWindowProperties; // profileId->Window
std::vector<UIMenuProperties> mUIMenuProperties;

};
