#include "include/global.hpp"

GameSceneImpl::GameSceneImpl(const std::string & sceneId) : BaseScene(sceneId)
{
    mMusicTrackIds.push_back("GameScene1");
    mMusicTrackIds.push_back("GameScene2");
    mMusicTrackIds.push_back("GameScene3");

    WorldManager::Instance().loadWorld("testWorld");
}

GameSceneImpl::~GameSceneImpl()
{

}
