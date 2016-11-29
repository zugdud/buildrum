class ConfigManager
{

static ConfigManager *mSingletonInstance;

public:

static ConfigManager * getInstance();

const MenuPropertiesContainer &getMenuPropertiesContainer(const std::string &uiMenuId);
const GameInstanceProperties &getGameInstanceProperties();

void reloadDynamicData();
void loadConstants();

private:

ConfigManager();
~ConfigManager();

void loadGameInstanceConstants();
void loadMenuConstants();

void addMenu(IMenuProperties & menuPropertiesImpl);

GameInstanceProperties mGameInstanceProperties;
std::map<std::string, MenuPropertiesContainer> mMenuPropertiesContainers;

};
