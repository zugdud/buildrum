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
    attachInputToUIMenus();
    attachInputManagerToCamera(); // only needed once
    attachUIElementsToEventManager();     // only needed once
    SDL_Log("----------------------------------------------------");
}

void StartSceneImpl::detatch()
{
    SDL_Log("----------------------------------------------------");
    SDL_Log("StartSceneImpl::detatch -- removing handlers from sceneId: %s \n", mSceneId.c_str());
    detatchLayersFromMenuRenderer();
    detatchSceneRenderersFromViewports();
    detatchInputFromUIMenus();
    // detatchUIElementsFromEventManager();   TODO not needed, would only make button point to np
    SDL_Log("----------------------------------------------------");
}
