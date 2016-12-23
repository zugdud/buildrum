class ConfigManager
{

static ConfigManager *mSingletonInstance;

public:

static ConfigManager * getInstance();


const std::vector<std::string> & getMenuIds();

IMenuProperties * getIMenuProperties(const std::string &uiMenuId);

const EnvironmentMediaPropertiesImpl &getEnvironmentMediaPropertiesImpl();
const FontProfileImpl &getFontProfileImpl();
const WindowPropertiesImpl &getWindowPropertiesImpl();
const AudioContentImpl & getAudioContentImpl();
const SpriteSheetPropertiesImpl & getSpriteSheetPropertiesImpl();
const SurfacePropertiesImpl & getSurfacePropertiesImpl();
const CameraPropertiesImpl & getCameraPropertiesImpl();

void reloadDynamicData();
void loadConstants();

private:

ConfigManager();
~ConfigManager();

void loadWindowProperties();
void loadMenuConstants();

void addMenu(IMenuProperties *menuProperties);

EnvironmentMediaPropertiesImpl mEnvironmentMediaPropertiesImpl;
FontProfileImpl mFontProfileImpl;
WindowPropertiesImpl mWindowPropertiesImpl;
AudioContentImpl mAudioContentImpl;
SpriteSheetPropertiesImpl mSpriteSheetPropertiesImpl;
SpritePropertiesImpl mSpritePropertiesImpl;
SurfacePropertiesImpl mSurfacePropertiesImpl;
InanimateObjectPropertiesImpl mInanimateObjectPropertiesImpl;

CameraPropertiesImpl mCameraPropertiesImpl;

std::vector<std::string> mMenuIds;
std::map<std::string, IMenuProperties *> mIMenuProperties; // menuId->MenuProperties

};
