#include "include/global.hpp"

HandleMoveCamera::HandleMoveCamera(const std::string & eventId)
{
    mEventId = eventId;
}

HandleMoveCamera::~HandleMoveCamera()
{

}

void HandleMoveCamera::handleEvent(IEventDispatch *eventManager)
{
    if (mEventId != "")
    {
        Player::Instance().setAction(MOVE_ACTION);
        UIMenu *uiMenu = MenuManager::Instance().getUIMenu("ActionMenu");
        uiMenu->setSelectedButton(mEventId);
    }
    else
    {
        SDL_Log("HandleMoveCamera::handleEvent -- ERROR: mEntityId was not set \n");
    }
}
