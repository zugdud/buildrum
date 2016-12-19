#include "include/global.hpp"

StartSceneImpl::StartSceneImpl(const std::string & sceneId) : BaseScene(sceneId)
{
    // add to music play list
    mMusicTrackIds.push_back("MainMenu");

    // add  menus
    mMenuIds.push_back("MainMenu");
}

StartSceneImpl::~StartSceneImpl()
{

}

void StartSceneImpl::attach()
{
    SDL_Log("StartSceneImpl::attach -- attaching handlers to sceneId: %s \n", mSceneId.c_str());
    attachLayersToMenuRenderer();
    attachSceneRenderersToViewports();
    attachInputManagerToUIElements();
    attachInputManagerToCamera(); // only needed once
    attachUIElementsToEventManager();     // only needed once
    attachWorld();
    attachUIMenuAsEventObserver();
    SDL_Log("----------------------------------------------------");
}

void StartSceneImpl::detatch()
{
    SDL_Log("----------------------------------------------------");
    SDL_Log("StartSceneImpl::detatch -- removing handlers from sceneId: %s \n", mSceneId.c_str());
    detatchLayersFromMenuRenderer();
    detatchSceneRenderersFromViewports();
    detatchInputManagerFromUIElements();
    detatchWorld();
    detatchUIMenuAsEventObserver();
    // detatchUIElementsFromEventManager();   TODO not needed, would only make button point to np
    SDL_Log("----------------------------------------------------");
}
