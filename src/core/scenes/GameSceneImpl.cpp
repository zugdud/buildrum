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
    attachUIElementsToEventManager();     // only needed once
    attachWorld();
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
    // detatchUIElementsFromEventManager();   TODO not needed, would only make button point to np
    SDL_Log("----------------------------------------------------");
}

void GameSceneImpl::doLoadAction()
{
    SDL_Log("GameSceneImpl::doLoad \n");
}

void GameSceneImpl::detatchWorld()
{
    for (size_t i = 0; i < mViewports.size(); i++)
    {
        const ViewportProperties & viewportProperties = mViewports[i].getViewportProperties();
        SDL_Log("GameSceneImpl::detatchWorld -- viewportId: %s \n", viewportProperties.viewportId.c_str());
        if (viewportProperties.viewportId == mWorldRendererViewportId)
        {
            // detatch, stop rendering, remains configured to viewport
            mWorldRenderer.detatch();

            // detatch the renderer from viewport, viewport will no longer invoke render calls
            mViewports[i].detatchWorldRenderer();

            // remove world as observer of input events
            WorldManager::Instance().getWorldPtr()->detatchInput();

            // register world with TimerManager
            TimerManager::Instance().removeBuildTimerObserver(WorldManager::Instance().getWorld().getWorldProperties().worldId);

        }
        else if (viewportProperties.viewportId == mMinimapViewportId)
        {
            // detatch the renderer from viewport, viewport will no longer invoke render calls
            mViewports[i].detatchMinimapRenderer();

            // detatch, stop rendering, remains configured to viewport
            mMinimapRenderer.detatch();
        }
        else if (viewportProperties.viewportId == mSelectedActionViewportId)
        {
            // attach the renderer to viewport
            mViewports[i].detatchSelectedActionRenderer();

            // configure detatchSelectedActionRenderer for the viewport
            mSelectedActionMenuRenderer.detatch();
        }
        else if (viewportProperties.viewportId == mStatusMenuViewportId)
        {
            // attach the renderer to viewport
            mViewports[i].detatchStatusMenuRenderer();

            // configure detatchStatusMenuRenderer for the viewport
            mStatusMenuRenderer.detatch();
        }
    }
}

void GameSceneImpl::attachWorld()
{
    for (size_t i = 0; i < mViewports.size(); i++)
    {
        const ViewportProperties & viewportProperties = mViewports[i].getViewportProperties();
        SDL_Log("GameSceneImpl::attachWorld -- viewportId: %s \n", viewportProperties.viewportId.c_str());
        if (viewportProperties.viewportId == mWorldRendererViewportId)
        {
            // configure renderer for the viewport
            mWorldRenderer.attach(mViewports[i]);

            // attach the renderer to the viewport
            mViewports[i].attachWorldRenderer(&mWorldRenderer);

            // set camera size for the viewport
            Camera::Instance().updateSize(mViewports[i].getRect());

            // attach world to camera
            Camera::Instance().registerObserver(WorldManager::Instance().getWorldPtr());

            // attach world to Observer input events
            WorldManager::Instance().getWorldPtr()->attachInput();

            // register world with TimerManager
            TimerManager::Instance().registerBuildTimerObserver(WorldManager::Instance().getWorldPtr());
        }
        else if (viewportProperties.viewportId == mMinimapViewportId)
        {
            // attach the renderer to viewport
            mViewports[i].attachMinimapRenderer(&mMinimapRenderer);

            // configure minimap for the viewport
            mMinimapRenderer.attach(mViewports[i]);
        }
        else if (viewportProperties.viewportId == mSelectedActionViewportId)
        {
            // attach the renderer to viewport
            mViewports[i].attachSelectedActionMenuRenderer(&mSelectedActionMenuRenderer);

            // configure attachSelectedActionMenuRenderer for the viewport
            mSelectedActionMenuRenderer.attach(mViewports[i]);
        }
        else if (viewportProperties.viewportId == mStatusMenuViewportId)
        {
            // attach the renderer to viewport
            mViewports[i].attachStatusMenuRenderer(&mStatusMenuRenderer);

            // configure attachStatusMenuRenderer for the viewport
            mStatusMenuRenderer.attach(mViewports[i]);
        }
    }
}
