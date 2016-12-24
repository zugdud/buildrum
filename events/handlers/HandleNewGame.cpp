#include "include/global.hpp"

HandleNewGame::HandleNewGame(const std::string & eventId)
{
    mEventId = eventId;
}

HandleNewGame::~HandleNewGame()
{

}

void HandleNewGame::handleEvent()
{
    AudioManager::Instance().stopMusic();
    SceneManager::getInstance()->setActiveScene("GameScene");
}
