#include "include/global.hpp"

GameSceneImpl::GameSceneImpl(const std::string & sceneId) : BaseScene(sceneId)
{
    // add to music play list
    mMusicTrackIds.push_back("GameScene1");
    mMusicTrackIds.push_back("GameScene2");
    mMusicTrackIds.push_back("GameScene3");

    // add  menus
    // mMenuIds.push_back("MainMenu");

    // add world view
    mWorldRendererViewportId = "gameView";
}

GameSceneImpl::~GameSceneImpl()
{

}