#include "include/global.hpp"

GameSceneImpl::GameSceneImpl()
{
    mSceneId = "GameScene";
    mViewContextId = "GameScene";

    mMusicTrackIds.push_back("GameScene1");
    mMusicTrackIds.push_back("GameScene2");
    mMusicTrackIds.push_back("GameScene3");

    mCurrentMusicTrackIdsIndex = 0;

    mWindow = WindowManager::getInstance()->getWindow();
    mAudioManager = &AudioManager::Instance();
    mViewports = WindowManager::getInstance()->getViewContext(mViewContextId).getViewports();
    mInputEventManager = InputEventManager::getInstance();

    init();
}

GameSceneImpl::~GameSceneImpl()
{

}

void GameSceneImpl::init()
{
    SDL_Log("GameSceneImpl::init -- creating mSceneId: %s mViewContextId: %s mMusicTrackIdsCount: %zu mMenuIdsCount: %zu \n",
            mSceneId.c_str(),
            mViewContextId.c_str(),
            mMusicTrackIds.size(),
            mMenuIds.size());
}

void GameSceneImpl::update()
{
    mWindow.clearScreen();
    for (size_t i = 0; i < mViewports.size(); i++)
    {
        handleMusicPlaylist();
        mViewports[i].renderUpdate();
    }
    mWindow.updateScreen();
}

void GameSceneImpl::handleMusicPlaylist()
{
    if (mAudioManager->getMusicPlayerState() == STOPPED)
    {
        mCurrentMusicTrackIdsIndex++;
        if (mCurrentMusicTrackIdsIndex >= mMusicTrackIds.size())
        {
            mCurrentMusicTrackIdsIndex = 0;
        }
        mAudioManager->setMusicTrack(mMusicTrackIds[mCurrentMusicTrackIdsIndex]);
        mAudioManager->playMusic();
    }
}

const std::string & GameSceneImpl::getSceneId()
{
    return mSceneId;
}
const std::string & GameSceneImpl::getViewContextId()
{
    return mViewContextId;
}
const std::vector<std::string> & GameSceneImpl::getMusicTrackIds()
{
    return mMusicTrackIds;
}
const std::vector<std::string> & GameSceneImpl::getMenuIds()
{
    return mMenuIds;
}
