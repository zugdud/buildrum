#include "include/global.hpp"

GameSceneImpl::GameSceneImpl(const std::string & sceneId) : BaseScene(sceneId)
{
    // add to music play list
    mMusicTrackIds.push_back("GameScene1");
    mMusicTrackIds.push_back("GameScene2");
    mMusicTrackIds.push_back("GameScene3");

    // add  menus
    mMenuIds.push_back("ActionMenu");
    mMenuIds.push_back("BuildMenu");

    // add world view
    mWorldRendererViewportId = "gameView";
    mMinimapViewportId = "minimap";
    mSelectedActionViewportId = "selectedAction";
    mStatusMenuViewportId = "statusMenu";
}

GameSceneImpl::~GameSceneImpl()
{

}

void GameSceneImpl::attach()
{
    SDL_Log("----------------------------------------------------");
    doLoadAction();
    SDL_Log("----------------------------------------------------");
    SDL_Log("GameSceneImpl::attach -- attaching handlers to sceneId: %s \n", mSceneId.c_str());
    attachLayersToMenuRenderer();
    attachSceneRenderersToViewports();
    attachInputToUIMenus();
    attachInputManagerToCamera(); // only needed once
    attachUIElementsToEventManager();     // only needed once
    attachWorld();
    attachUIMenuAsEventObserver();
    SDL_Log("----------------------------------------------------");
}

void GameSceneImpl::detatch()
{
    SDL_Log("----------------------------------------------------");
    SDL_Log("GameSceneImpl::detatch -- removing handlers from sceneId: %s \n", mSceneId.c_str());
    detatchLayersFromMenuRenderer();
    detatchSceneRenderersFromViewports();
    detatchInputFromUIMenus();
    detatchWorld();
    detatchUIMenuAsEventObserver();
    // detatchUIElementsFromEventManager();   TODO not needed, would only make button point to np
    SDL_Log("----------------------------------------------------");
}

void GameSceneImpl::doLoadAction()
{
    SDL_Log("GameSceneImpl::doLoad \n");
    WorldManager::Instance().loadWorld("testWorld");
}
