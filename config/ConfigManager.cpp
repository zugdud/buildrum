#include "include/global.hpp"

ConfigManager *ConfigManager::mSingletonInstance = 0;

ConfigManager::ConfigManager()
{
    SDL_Log("ConfigManager Instantiated. \n");
}

ConfigManager::~ConfigManager()
{

}

ConfigManager * ConfigManager::getInstance()
{
    if (!mSingletonInstance)
    {
        mSingletonInstance = new ConfigManager;
    }
    return mSingletonInstance;
}

const CameraPropertiesImpl & ConfigManager::getCameraPropertiesImpl()
{
    return mCameraPropertiesImpl;
}

const SurfacePropertiesImpl & ConfigManager::getSurfacePropertiesImpl()
{
    return mSurfacePropertiesImpl;
}

const std::vector<std::string> & ConfigManager::getMenuIds()
{
    return mMenuIds;
}

IMenuProperties * ConfigManager::getIMenuProperties(const std::string &uiMenuId)
{
    return mIMenuProperties[uiMenuId];
}

const EnvironmentMediaPropertiesImpl & ConfigManager::getEnvironmentMediaPropertiesImpl()
{
    return mEnvironmentMediaPropertiesImpl;
}

const AudioContentImpl & ConfigManager::getAudioContentImpl()
{
    return mAudioContentImpl;
}

const FontProfileImpl & ConfigManager::getFontProfileImpl()
{
    return mFontProfileImpl;
}

const WindowPropertiesImpl & ConfigManager::getWindowPropertiesImpl()
{
    return mWindowPropertiesImpl;
}

const SpriteSheetPropertiesImpl & ConfigManager::getSpriteSheetPropertiesImpl()
{
    return mSpriteSheetPropertiesImpl;
}

void ConfigManager::reloadDynamicData()
{

}

void ConfigManager::loadConstants()
{
    SDL_Log("----------------------------------------------------\n");
    SDL_Log("ConfigManager::loadConstants -- loading contants...\n");
    mWindowPropertiesImpl.loadAll();
    mEnvironmentMediaPropertiesImpl.loadAll();
    mFontProfileImpl.loadAll();
    mAudioContentImpl.loadAll();
    mSpriteSheetPropertiesImpl.loadAll();
    mSpritePropertiesImpl.loadAll();
    mCameraPropertiesImpl.loadAll();
    mSurfacePropertiesImpl.loadAll();
    mInanimateObjectPropertiesImpl.loadAll();
    loadMenuConstants();
    SDL_Log("ConfigManager::loadConstants -- all contants loaded!\n");
    SDL_Log("----------------------------------------------------\n");
}

void ConfigManager::loadMenuConstants()
{
    addMenu(new MainMenuPropertiesImpl());
    addMenu(new ActionMenuPropertiesImpl());
    addMenu(new BuildMenuPropertiesImpl());
    addMenu(new SelectedActionMenuPropertiesImpl());
    addMenu(new StatusMenuPropertiesImpl());
}

void ConfigManager::addMenu(IMenuProperties *menuProperties)
{
    menuProperties->setProperties();
    std::string uiMenuId = menuProperties->getUIMenuProperties().uiMenuId;
    mMenuIds.push_back(uiMenuId);
    mIMenuProperties[uiMenuId] = menuProperties;
    SDL_Log("ConfigManager::addMenu -- added uiMenuId: %s \n", uiMenuId.c_str());
}
