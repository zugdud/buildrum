class ConfigManager
{

static ConfigManager *mSingletonInstance;

public:

static ConfigManager * getInstance();


const std::vector<std::string> & getMenuIds();

const MenuPropertiesContainer &getMenuPropertiesContainer(const std::string &uiMenuId);

const EnvironmentMediaPropertiesImpl &getEnvironmentMediaPropertiesImpl();
const FontProfileImpl &getFontProfileImpl();
const WindowPropertiesImpl &getWindowPropertiesImpl();

void reloadDynamicData();
void loadConstants();

private:

ConfigManager();
~ConfigManager();

void loadWindowProperties();
void loadMenuConstants();

void addMenu(IMenuProperties & menuPropertiesImpl);

EnvironmentMediaPropertiesImpl mEnvironmentMediaPropertiesImpl;
FontProfileImpl mFontProfileImpl;
WindowPropertiesImpl mWindowPropertiesImpl;

std::vector<std::string> mMenuIds;
std::map<std::string, MenuPropertiesContainer> mMenuPropertiesContainers; // menuId->MenuPropertiesContainer

};
