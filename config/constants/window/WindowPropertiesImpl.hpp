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

std::string windowProfile;

std::vector<ViewContextProperties> mViewContextProperties;
WindowProperties mWindowProperties;
std::vector<UIMenuProperties> mUIMenuProperties;

};
