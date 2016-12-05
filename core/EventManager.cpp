#include "include/global.hpp"

EventManager *EventManager::mSingletonInstance = 0;

EventManager::EventManager()
{

}

EventManager::~EventManager()
{

}

EventManager * EventManager::getInstance()
{
    if (!mSingletonInstance)
    {
        mSingletonInstance = new EventManager;
    }
    return mSingletonInstance;
}

void EventManager::configure(AudioManager *audioManager)
{
    SDL_Log("EventManager::configure -- configuring... \n");
    mAudioManager = audioManager;
}

void EventManager::uiEventRaised(const std::string & eventId)
{
    SDL_Log("EventManager::uiEventRaised -- eventId: %s \n", eventId.c_str());
    mAudioManager->playSound("pop_1");
    if (eventId == "newGame")
    {
        AudioManager::Instance().stopMusic();
        SceneManager::getInstance()->setActiveScene("GameScene");
    }
}

// play music
// AudioManager::Instance().setMusicTrack("MainMenu");
// AudioManager::Instance().playMusic();
// AudioManager::Instance().stopMusic();
