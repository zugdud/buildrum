#include "include/global.hpp"

BaseScene::BaseScene(const std::string & sceneId)
{
    mSceneId = sceneId;
    mViewContextId = sceneId;

    mCurrentMusicTrackIdsIndex = 0;
    mWindow = WindowManager::getInstance()->getWindow();
    mViewports = WindowManager::getInstance()->getViewContext(mViewContextId).getViewports();
    mInputEventManager = InputEventManager::getInstance();

    SDL_Log("BaseScene::init -- creating mSceneId: %s mViewContextId: %s mMusicTrackIdsCount: %zu mMenuIdsCount: %zu \n",
            mSceneId.c_str(),
            mViewContextId.c_str(),
            mMusicTrackIds.size(),
            mMenuIds.size());
}

BaseScene::~BaseScene()
{

}

void BaseScene::update()
{
    mWindow.clearScreen();
    for (size_t i = 0; i < mViewports.size(); i++)
    {
        handleMusicPlaylist();
        mViewports[i].renderUpdate();
    }
    mWindow.updateScreen();
}

void BaseScene::handleMusicPlaylist()
{
    if (AudioManager::Instance().getMusicPlayerState() == STOPPED)
    {
        mCurrentMusicTrackIdsIndex++;
        if (mCurrentMusicTrackIdsIndex >= mMusicTrackIds.size())
        {
            mCurrentMusicTrackIdsIndex = 0;
        }
        AudioManager::Instance().setMusicTrack(mMusicTrackIds[mCurrentMusicTrackIdsIndex]);
        AudioManager::Instance().playMusic();
    }
}


void BaseScene::attach()
{
    SDL_Log("----------------------------------------------------");
    WorldManager::Instance().loadWorld("testWorld");
    SDL_Log("----------------------------------------------------");
    SDL_Log("BaseScene::attach -- attaching handlers to sceneId: %s \n", mSceneId.c_str());
    attachLayersToMenuRenderer();
    attachSceneRenderersToViewports();
    attachInputManagerToUIElements();
    attachInputManagerToCamera(); // only needed once
    attachUIElementsToEventManager();     // only needed once
    attachWorld();
    attachUIMenuAsEventObserver();
    SDL_Log("----------------------------------------------------");
}

void BaseScene::detatch()
{
    SDL_Log("----------------------------------------------------");
    SDL_Log("BaseScene::detatch -- removing handlers from sceneId: %s \n", mSceneId.c_str());
    detatchLayersFromMenuRenderer();
    detatchSceneRenderersFromViewports();
    detatchInputManagerFromUIElements();
    detatchWorld();
    detatchUIMenuAsEventObserver();
    // detatchUIElementsFromEventManager();   TODO not needed, would only make button point to np
    SDL_Log("----------------------------------------------------");
}

//
void BaseScene::detatchLayersFromMenuRenderer()
{
    for (size_t i = 0; i < mMenuIds.size(); i++)
    {
        mMenuRenderer.removeLayer(mMenuIds[i]);
    }
}

void BaseScene::detatchSceneRenderersFromViewports()
{
    // remove renderers from viewports
    for (size_t i = 0; i < mViewports.size(); i++)
    {
        mViewports[i].removeAllRenderers();
    }
}

void BaseScene::detatchInputManagerFromUIElements()
{
    // each menu
    for (size_t i = 0; i < mMenuIds.size(); i++)
    {
        // detatch input handler to ui elements
        std::vector<UIGridCell> & uiGridCells = MenuManager::Instance().getUIMenu(mMenuIds[i])->getGridCells();
        for (size_t i = 0; i < uiGridCells.size(); i++)
        {
            mInputEventManager->removePointEventObserver(uiGridCells[i].getUIButton()->getId());
        }
    }
}

void BaseScene::attachInputManagerToCamera()
{
    SDL_Log("BaseScene::attachInputManagerToCamera -- attaching camera to inputeventmanager \n");
    mInputEventManager->registerScrollEventObserver(&Camera::Instance());
    mInputEventManager->registerZoomEventObserver(&Camera::Instance());
}

void BaseScene::detatchWorld()
{
    for (size_t i = 0; i < mViewports.size(); i++)
    {
        const ViewportProperties & viewportProperties = mViewports[i].getViewportProperties();
        SDL_Log("BaseScene::detatchWorld -- viewportId: %s \n", viewportProperties.viewportId.c_str());
        if (viewportProperties.viewportId == mWorldRendererViewportId)
        {
            // detatch, stop rendering, remains configured to viewport
            mWorldRenderer.detatch();

            // detatch the renderer from viewport, viewport will no longer invoke render calls
            mViewports[i].detatchWorldRenderer();

        }
        else if (viewportProperties.viewportId == mMinimapViewportId)
        {
            // detatch the renderer from viewport, viewport will no longer invoke render calls
            mViewports[i].detatchMinimapRenderer();

            // detatch, stop rendering, remains configured to viewport
            mMinimapRenderer.detatch();
        }
    }
}

void BaseScene::attachWorld()
{
    for (size_t i = 0; i < mViewports.size(); i++)
    {
        const ViewportProperties & viewportProperties = mViewports[i].getViewportProperties();
        SDL_Log("BaseScene::attachWorld -- viewportId: %s \n", viewportProperties.viewportId.c_str());
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
        }
        else if (viewportProperties.viewportId == mMinimapViewportId)
        {
            // attach the renderer to viewport
            mViewports[i].attachMinimapRenderer(&mMinimapRenderer);

            // configure minimap for the viewport
            mMinimapRenderer.attach(mViewports[i]);
        }
    }
}

void BaseScene::attachLayersToMenuRenderer()
{
    for (size_t i = 0; i < mMenuIds.size(); i++)
    {
        mMenuRenderer.addLayer(MenuManager::Instance().getUIMenu(mMenuIds[i]));
    }
}

void BaseScene::attachSceneRenderersToViewports()
{
    // attach renderers to viewports
    for (size_t i = 0; i < mViewports.size(); i++)
    {
        mViewports[i].addRenderer(&mMenuRenderer);
    }
}

void BaseScene::attachInputManagerToUIElements()
{
    // each menu
    for (size_t i = 0; i < mMenuIds.size(); i++)
    {
        // attach input handler to ui elements
        std::vector<UIGridCell> & uiGridCells = MenuManager::Instance().getUIMenu(mMenuIds[i])->getGridCells();
        for (size_t i = 0; i < uiGridCells.size(); i++)
        {
            mInputEventManager->registerPointEventObserver(uiGridCells[i].getUIButton());
        }
    }
}
void BaseScene::detatchUIMenuAsEventObserver()
{
    SDL_Log("BaseScene::detatchUIMenuAsEventObserver -- Detatching UI Menus from event manager");
    // each menu
    for (size_t i = 0; i < mMenuIds.size(); i++)
    {
        EventManager::getInstance()->removeObserver(mMenuIds[i]);
    }
}

void BaseScene::attachUIMenuAsEventObserver()
{
    SDL_Log("BaseScene::attachUIMenuAsEventObserver -- Attaching UI Menus to event manager");
    // each menu
    for (size_t i = 0; i < mMenuIds.size(); i++)
    {
        EventManager::getInstance()->registerObserver(MenuManager::Instance().getUIMenu(mMenuIds[i]));
    }
}

void BaseScene::attachUIElementsToEventManager()
{
    // each menu
    for (size_t i = 0; i < mMenuIds.size(); i++)
    {
        // attach UI elements to event handler
        std::vector<UIGridCell> & uiGridCells = MenuManager::Instance().getUIMenu(mMenuIds[i])->getGridCells();
        for (size_t i = 0; i < uiGridCells.size(); i++)
        {
            uiGridCells[i].getUIButton()->setUIEventConnector(EventManager::getInstance());
        }
    }
}


const std::string & BaseScene::getSceneId()
{
    return mSceneId;
}
const std::string & BaseScene::getViewContextId()
{
    return mViewContextId;
}
const std::vector<std::string> & BaseScene::getMusicTrackIds()
{
    return mMusicTrackIds;
}
const std::vector<std::string> & BaseScene::getMenuIds()
{
    return mMenuIds;
}
