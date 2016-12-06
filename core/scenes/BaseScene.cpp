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
    attachLayersToMenuRenderer();
    attachSceneRenderersToViewports();
    attachInputManagerToUIElements();
    attachUIElementsToEventManager();
}

void BaseScene::detatch()
{
    detatchLayersFromMenuRenderer();
    detatchSceneRenderersFromViewports();
    // detatchInputManagerToUIElements();
    // detatchUIElementsToEventManager();
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
//
// void StartSceneImpl::attachInputManagerToUIElements()
// {
//     // each menu
//     for (size_t i = 0; i < mMenuIds.size(); i++)
//     {
//         // attach input handler to ui elements
//         std::vector<UIGridCell> & uiGridCells = MenuManager::Instance().getUIMenu(mMenuIds[i])->getGridCells();
//         for (size_t i = 0; i < uiGridCells.size(); i++)
//         {
//             mInputEventManager->registerPointEventObserver(uiGridCells[i].getUIButton());
//         }
//     }
// }
//
// void StartSceneImpl::attachUIElementsToEventManager()
// {
//     // attach UI elements to event handler
//     std::vector<UIGridCell> & uiGridCells = MenuManager::Instance().getUIMenu(mSceneId)->getGridCells();
//     for (size_t i = 0; i < uiGridCells.size(); i++)
//     {
//         uiGridCells[i].getUIButton()->setUIEventConnector(EventManager::getInstance());
//     }
// }

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
