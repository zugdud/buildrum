#include "include/global.hpp"

MenuManager::MenuManager()
{

}

MenuManager::~MenuManager()
{

}

const UIMenu & MenuManager::getUIMenu(const std::string & menuId)
{
    return mUiMenus.at(menuId);
}

void MenuManager::configure()
{
    const std::vector<std::string> & menuIds = ConfigManager::getInstance()->getMenuIds();
    for (size_t i = 0; i < menuIds.size(); i++)
    {
        UIMenu uiMenu;
        uiMenu.configure(ConfigManager::getInstance()->getMenuPropertiesContainer(menuIds[i]));
        mUiMenus.insert(std::pair<std::string, UIMenu>(menuIds[i], uiMenu) );
    }
}

void MenuManager::repositionMenu(const std::string & menuId, const SDL_Rect & envelope)
{
    mUiMenus.at(menuId).resetPosition(envelope);
}
