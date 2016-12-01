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

const FontProfileImpl & ConfigManager::getFontProfileImpl()
{
    return mFontProfileImpl;
}

const WindowPropertiesImpl & ConfigManager::getWindowPropertiesImpl()
{
    return mWindowPropertiesImpl;
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
    loadMenuConstants();
    SDL_Log("ConfigManager::loadConstants -- all contants loaded!\n");
    SDL_Log("----------------------------------------------------\n");
}

void ConfigManager::loadMenuConstants()
{
    addMenu(new MainMenuPropertiesImpl());
}

void ConfigManager::addMenu(IMenuProperties *menuProperties)
{
    menuProperties->setProperties();
    std::string uiMenuId = menuProperties->getUIMenuProperties().uiMenuId;
    mMenuIds.push_back(uiMenuId);
    mIMenuProperties[uiMenuId] = menuProperties;
    SDL_Log("ConfigManager::addMenu -- added uiMenuId: %s \n", uiMenuId.c_str());
}
