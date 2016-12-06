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
