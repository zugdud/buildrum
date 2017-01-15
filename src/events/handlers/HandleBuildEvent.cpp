#include "include/global.hpp"

HandleBuildEvent::HandleBuildEvent(const std::string & eventId)
{
    mEventId = eventId;
    mEntityId = "";
    std::size_t found = eventId.find("build");
    if (found != std::string::npos)
    {
        mEntityId = eventId.substr(6, eventId.length());
        SDL_Log("HandleBuildEvent::HandleBuildEvent -- mEventId: %s mEntityId: %s \n",
                mEventId.c_str(),
                mEntityId.c_str());
    }
}

HandleBuildEvent::~HandleBuildEvent()
{

}

void HandleBuildEvent::handleEvent(IEventDispatch *eventManager)
{
    if (mEntityId != "")
    {
        Player::Instance().setBuildableAction(mEntityId);
        std::vector<UIGridCell> & actionMenuGridCells = MenuManager::Instance().getUIMenu("ActionMenu")->getGridCells();
        for (size_t i = 0; i < actionMenuGridCells.size(); i++)
        {
            UIButton *uiButton = actionMenuGridCells[i].getUIButton();
            const UIButtonProperties & uiButtonProperties = uiButton->getUIButtonProperties();
            if (uiButtonProperties.buttonId == "toggleHidden_BuildMenu")
            {
                uiButton->updateAllButtonStateSprites(mEntityId);
            }
        }
        eventManager->dispatchEvent("toggleHidden_BuildMenu");
    }
    else
    {
        SDL_Log("HandleBuildEvent::handleEvent -- ERROR: mEntityId was not set \n");
    }
}
