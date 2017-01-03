#include "include/global.hpp"

HandleExitGame::HandleExitGame(const std::string & eventId)
{
    mEventId = eventId;
}

HandleExitGame::~HandleExitGame()
{

}

void HandleExitGame::handleEvent(IEventDispatch *eventManager)
{
    AudioManager::Instance().stopMusic();
}
