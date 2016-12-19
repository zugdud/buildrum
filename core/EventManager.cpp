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

void EventManager::registerObserver(IEventObserver *eventObserver)
{
    SDL_Log("EventManager::registerObserver -- registering observer id: %s \n", eventObserver->getId().c_str());
    mEventObservers.push_back(eventObserver);
}

void EventManager::removeObserver(const std::string & id)
{
    for (size_t i = 0; i < mEventObservers.size(); i++)
    {
        if (mEventObservers[i]->getId() == id)
        {
            SDL_Log("EventManager::removeObserver -- removing observer id: %s \n", id.c_str());
            mEventObservers.erase(mEventObservers.begin() + i);
        }
    }
}

void EventManager::dispatchEvent(const std::string & eventId)
{
    for (size_t i = 0; i < mEventObservers.size(); i++)
    {
        mEventObservers[i]->eventRaised(eventId);
    }
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
    if (eventId == "quitGame")
    {
        AudioManager::Instance().stopMusic();
        SceneManager::getInstance()->setActiveScene("MainMenu");
    }
    dispatchEvent(eventId);
}

// play music
// AudioManager::Instance().setMusicTrack("MainMenu");
// AudioManager::Instance().playMusic();
// AudioManager::Instance().stopMusic();
