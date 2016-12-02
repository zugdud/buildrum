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
    SDL_Log("----------------------------------------------------\n");
    SDL_Log("MenuManager::configure -- configuring menus...\n");
    const std::vector<std::string> & menuIds = ConfigManager::getInstance()->getMenuIds();
    for (size_t i = 0; i < menuIds.size(); i++)
    {
        UIMenu uiMenu;
        uiMenu.configure(ConfigManager::getInstance()->getIMenuProperties(menuIds[i]));
        mUiMenus.insert(std::pair<std::string, UIMenu>(menuIds[i], uiMenu) );
        SDL_Log("MenuManager::configure -- added menu menuId: %s \n", menuIds[i].c_str());
    }
    SDL_Log("----------------------------------------------------\n");

}
