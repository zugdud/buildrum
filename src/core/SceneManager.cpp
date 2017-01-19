#include "include/global.hpp"

SceneManager *SceneManager::mSingletonInstance = 0;

SceneManager::SceneManager()
{
    mUpdateLock = false;
}

SceneManager::~SceneManager()
{

}

SceneManager * SceneManager::getInstance()
{
    if (!mSingletonInstance)
    {
        mSingletonInstance = new SceneManager;
    }
    return mSingletonInstance;
}

SelectedPoint SceneManager::getViewportOffset(const PointInt & pointEvent)
{
    SelectedPoint selectedPoint;

    selectedPoint.viewportOffset.x = 0;
    selectedPoint.viewportOffset.y = 0;
    selectedPoint.viewportId = "";

    const std::vector<Viewport> & viewports = mScenes[mActiveSceneId]->getViewports();
    for (size_t i = 0; i < viewports.size(); i++)
    {
        if (isPointInViewport(pointEvent, viewports[i].getRect()))
        {
            selectedPoint.viewportOffset.x = viewports[i].getRect().x;
            selectedPoint.viewportOffset.y = viewports[i].getRect().y;
            selectedPoint.viewportId = viewports[i].getViewportProperties().viewportId.c_str();
        }
    }
    return selectedPoint;
}

// TODO
bool SceneManager::isPointInViewport(const PointInt & pointInt, const SDL_Rect & rect)
{
    if (pointInt.x >= rect.x && pointInt.x <= (rect.x + rect.w) )
    {
        if (pointInt.y >= rect.y && pointInt.y <= (rect.y + rect.h) )
        {
            return true;
        }
    }
    return false;
}

void SceneManager::init()
{
    mScenes["MainMenu"] = new StartSceneImpl("MainMenu");
    mScenes["GameScene"] = new GameSceneImpl("GameScene");
    mScenes["LoadingScene"] = new LoadingSceneImpl("LoadingScene");

    // attach to active scene
    mActiveSceneId = "MainMenu";
    mScenes[mActiveSceneId]->attach();

}

void SceneManager::setUpdateLock(const bool & lockState)
{
    mUpdateLock = lockState;
    SDL_Log("SceneManager::setUpdateLock -- mUpdateLock: %d \n", mUpdateLock);
}

const bool & SceneManager::getUpdateLock()
{
    return mUpdateLock;
}

void SceneManager::setActiveScene(const std::string & activeSceneId)
{
    mScenes[mActiveSceneId]->detatch();
    mActiveSceneId = activeSceneId;
    mScenes[mActiveSceneId]->attach();
}

void SceneManager::updateActiveScene()
{
    if (mUpdateLock == false)
    {
        mScenes[mActiveSceneId]->update();
    }
}
