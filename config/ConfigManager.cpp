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

const MenuPropertiesContainer & ConfigManager::getMenuPropertiesContainer(const std::string &uiMenuId)
{
    return mMenuPropertiesContainers[uiMenuId];
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

    MainMenuPropertiesImpl mainMenuPropertiesImpl;

    addMenu(mainMenuPropertiesImpl);
}

void ConfigManager::addMenu(IMenuProperties & menuPropertiesImpl)
{
    MenuPropertiesContainer menuPropertiesContainer;

    menuPropertiesImpl.setProperties(menuPropertiesContainer);
    std::string uiMenuId = menuPropertiesContainer.getUIMenuProperties().uiMenuId;
    mMenuPropertiesContainers[uiMenuId] = menuPropertiesContainer;
    SDL_Log("ConfigManager::addMenu -- added uiMenuId: %s \n", uiMenuId.c_str());
}
