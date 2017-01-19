#include "include/global.hpp"

static int loadingSceneThread(void *ptr)
{
    SDL_Log("LoadingSceneImpl::backgroundThread -- Loading World... \n");
    SceneManager::getInstance()->setUpdateLock(true);

    // TODO seperate render andling
    WindowManager::getInstance()->getWindow().clearScreen();
    WindowManager::getInstance()->getWindow().updateScreen();

    WorldManager::Instance().loadWorld("testWorld");
    SceneManager::getInstance()->setActiveScene("GameScene");
    SceneManager::getInstance()->setUpdateLock(false);

    return 1;
}

LoadingSceneImpl::LoadingSceneImpl(const std::string & sceneId) : BaseScene(sceneId)
{
    // add to music play list
    mMusicTrackIds.push_back("MainMenu");

    // add  menus
    mMenuIds.push_back("MainMenu");
}

LoadingSceneImpl::~LoadingSceneImpl()
{

}

void LoadingSceneImpl::attach()
{
    SDL_Log("LoadingSceneImpl::attach -- attaching handlers to sceneId: %s \n", mSceneId.c_str());
    startThread();
    SDL_Log("----------------------------------------------------");
}

void LoadingSceneImpl::detatch()
{
    SDL_Log("----------------------------------------------------");
    SDL_Log("LoadingSceneImpl::detatch -- removing handlers from sceneId: %s \n", mSceneId.c_str());

    SDL_Log("----------------------------------------------------");
}

void LoadingSceneImpl::startThread()
{
    SDL_Thread *thread;

    SDL_Log("LoadingSceneImpl::startThread -- starting thread... \n");

    thread = SDL_CreateThread(loadingSceneThread, "BackgroundThread", (void *) NULL);

    if (NULL == thread)
    {
        printf("SDL_CreateThread failed: %s\n", SDL_GetError());
    }
    // else
    // {
    //     SDL_WaitThread(thread, &threadReturnValue);
    // }
}
