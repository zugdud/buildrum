class ConfigManager
{

static ConfigManager *mSingletonInstance;

public:

static ConfigManager * getInstance();

const MenuPropertiesContainer &getMenuPropertiesContainer(const std::string &uiMenuId);
const WindowPropertiesImpl &getWindowPropertiesImpl();

void reloadDynamicData();
void loadConstants();

private:

ConfigManager();
~ConfigManager();

void loadWindowProperties();
void loadMenuConstants();

void addMenu(IMenuProperties & menuPropertiesImpl);

FontPropertiesImpl mFontPropertiesImpl;
WindowPropertiesImpl mWindowPropertiesImpl;
std::map<std::string, MenuPropertiesContainer> mMenuPropertiesContainers;

};
