#include "include/global.hpp"

EventManager *EventManager::mSingletonInstance = 0;

EventManager::EventManager()
{
    mEventHandlers["newGame"] = new HandleNewGame("newGame");
    mEventHandlers["mainMenu"] = new HandleMainMenu("mainMenu");
    mEventHandlers["exitGame"] = new HandleExitGame("exitGame");
    mEventHandlers["moveCamera"] = new HandleMoveCamera("moveCamera");

    mEventHandlers["toggleHidden_BuildMenu"] = new HandleToggleBuildMenu("toggleHidden_BuildMenu");

    mEventHandlers["build_banner_1"] = new HandleBuildEvent("build_banner_1");
    mEventHandlers["build_banner_2"] = new HandleBuildEvent("build_banner_2");
    mEventHandlers["build_emblem_2"] = new HandleBuildEvent("build_emblem_2");
    mEventHandlers["build_spire_1"] = new HandleBuildEvent("build_spire_1");
    mEventHandlers["build_ladder_1"] = new HandleBuildEvent("build_ladder_1");
    mEventHandlers["build_anvil_1"] = new HandleBuildEvent("build_anvil_1");
    mEventHandlers["build_anvil_2"] = new HandleBuildEvent("build_anvil_2");
    mEventHandlers["build_latern_1"] = new HandleBuildEvent("build_latern_1");
    mEventHandlers["build_crate_1"] = new HandleBuildEvent("build_crate_1");
    mEventHandlers["build_crate_2"] = new HandleBuildEvent("build_crate_2");
    mEventHandlers["build_crate_3"] = new HandleBuildEvent("build_crate_3");
    mEventHandlers["build_crate_4"] = new HandleBuildEvent("build_crate_4");
    mEventHandlers["build_crate_5"] = new HandleBuildEvent("build_crate_5");
    mEventHandlers["build_barrel_1"] = new HandleBuildEvent("build_barrel_1");

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
    if (mEventHandlers.count(eventId) == 1)
    {
        mEventHandlers[eventId]->handleEvent(this);
    }
    else
    {
        SDL_Log("EventManager::uiEventRaised -- ERROR - no handler for eventId: %s \n", eventId.c_str());
    }

    dispatchEvent(eventId);
}

// play music
// AudioManager::Instance().setMusicTrack("MainMenu");
// AudioManager::Instance().playMusic();
// AudioManager::Instance().stopMusic();
