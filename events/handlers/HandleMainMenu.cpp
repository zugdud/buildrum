#include "include/global.hpp"

HandleMainMenu::HandleMainMenu(const std::string & eventId)
{
    mEventId = eventId;
}

HandleMainMenu::~HandleMainMenu()
{

}

void HandleMainMenu::handleEvent()
{
    AudioManager::Instance().stopMusic();
    SceneManager::getInstance()->setActiveScene("MainMenu");
}
