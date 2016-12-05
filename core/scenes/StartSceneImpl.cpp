#include "include/global.hpp"

StartSceneImpl::StartSceneImpl()
{
    mSceneId = "MainMenu";
    mViewContextId = "MainMenu";
    mMusicTrackIds.push_back("MainMenu");
    mMenuIds.push_back("MainMenu");
    mCurrentMusicTrackIdsIndex = 0;

    mWindow = WindowManager::getInstance()->getWindow();
    mAudioManager = AudioManager::Instance();
    mViewports = WindowManager::getInstance()->getViewContext(mViewContextId).getViewports();
    mInputEventManager = InputEventManager::getInstance();

    init();
}

StartSceneImpl::~StartSceneImpl()
{

}

void StartSceneImpl::init()
{
    SDL_Log("StartSceneImpl::init -- creating mSceneId: %s mViewContextId: %s mMusicTrackIdsCount: %zu mMenuIdsCount: %zu \n",
            mSceneId.c_str(),
            mViewContextId.c_str(),
            mMusicTrackIds.size()
            mMenuIds.size());

    attachInputHandlers();
    attachInputHandlers();
    attachLayersToMenuRenderer();
    attachRenderersToViewports();
}

void StartSceneImpl::update()
{
    mWindow.clearScreen();
    for (size_t i = 0; i < mViewports.size(); i++)
    {
        handleMusicPlaylist();
        mViewports[i].renderUpdate();
    }
    mWindow.updateScreen();
}

void StartSceneImpl::handleMusicPlaylist()
{
    if (mAudioManager->getMusicPlayerState() == STOPPED)
    {
        mCurrentMusicTrackIdsIndex++;
        if (mCurrentMusicTrackIdsIndex > 0 && !mCurrentMusicTrackIdsIndex < mMusicTrackIds.size())
        {
            mCurrentMusicTrackIdsIndex = 0;
        }
        mAudioManager->setMusicTrack(mMusicTrackIds[mCurrentMusicTrackIdsIndex])
        mAudioManager->playMusic();
    }
}

void StartSceneImpl::attachLayersToMenuRenderer()
{
    for (size_t i = 0; i < mMenuIds.size(); i++)
    {
        mMenuRenderer->addLayer(MenuManager::Instance().getUIMenu(mMenuIds[i]));
    }
}

void StartSceneImpl::attachSceneRenderersToViewports()
{
    // attach renderers to viewports
    for (size_t i = 0; i < mViewports.size(); i++)
    {
        mViewports[i].addRenderer(mMenuRenderer);
    }
}

void StartSceneImpl::attachInputManagerToUIElements()
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

void StartSceneImpl::attachUIElementsToEventManager()
{
    // attach UI elements to event handler
    std::vector<UIGridCell> & uiGridCells = MenuManager::Instance().getUIMenu(mSceneId)->getGridCells();
    for (size_t i = 0; i < uiGridCells.size(); i++)
    {
        uiGridCells[i].getUIButton()->setUIEventConnector(EventManager::getInstance());
    }
}

const std::string & getSceneId()
{
    return mSceneId;
}
const std::string & getViewContextId()
{
    return mViewContextId;
}
const std::vector<std::string> & getMusicTrackIds()
{
    return mMusicTrackIds;
}
const std::vector<std::string> & getMenuIds()
{
    return mMenuIds;
}
