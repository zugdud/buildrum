#include "include/global.hpp"

SceneManager *SceneManager::mSingletonInstance = 0;

SceneManager::SceneManager()
{

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

PointInt SceneManager::getViewportOffset(const PointInt & pointEvent)
{
    SDL_Log("SceneManager::getViewportOffset -- pointEvent [x: %d y: %d] \n", pointEvent.x, pointEvent.y);

    PointInt viewportOffset = { 0, 0 };
    const std::vector<Viewport> & viewports = mScenes[mActiveSceneId]->getViewports();
    for (size_t i = 0; i < viewports.size(); i++)
    {
        if (isPointInViewport(pointEvent, viewports[i].getRect()))
        {
            SDL_Log("SceneManager::getViewportOffset -- clicked Viewport: [x: %d y: %d w: %d h: %d] id: %s \n",
                    viewports[i].getRect().x,
                    viewports[i].getRect().y,
                    viewports[i].getRect().w,
                    viewports[i].getRect().h,
                    viewports[i].getViewportProperties().viewportId.c_str());
            viewportOffset.x = viewports[i].getRect().x;
            viewportOffset.y = viewports[i].getRect().y;
        }
    }

    return viewportOffset;
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

    // attach to active scene
    mActiveSceneId = "MainMenu";
    mScenes[mActiveSceneId]->attach();

}

void SceneManager::setActiveScene(const std::string & activeSceneId)
{
    mScenes[mActiveSceneId]->detatch();
    mActiveSceneId = activeSceneId;
    mScenes[mActiveSceneId]->attach();
}

void SceneManager::updateActiveScene()
{
    mScenes[mActiveSceneId]->update();
}
