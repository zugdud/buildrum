#include "include/global.hpp"

HandleToggleBuildMenu::HandleToggleBuildMenu(const std::string & eventId)
{
    mEventId = eventId;
}

HandleToggleBuildMenu::~HandleToggleBuildMenu()
{

}

void HandleToggleBuildMenu::handleEvent(IEventDispatch *eventManager)
{
    if (mEventId != "")
    {
        UIMenu *uiMenu = MenuManager::Instance().getUIMenu("ActionMenu");
        Player::Instance().setAction(BUILD_ACTION);
        uiMenu->setSelectedButton(mEventId);

        UIMenu *buildMenu = MenuManager::Instance().getUIMenu("BuildMenu");
        buildMenu->toggleHidden();
    }
    else
    {
        SDL_Log("HandleToggleBuildMenu::handleEvent -- ERROR: mEntityId was not set \n");
    }
}
