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

void SceneManager::init()
{

    // start scene
    StartSceneImpl *startScene = new StartSceneImpl();

    mScenes[startScene->getSceneId()] = startScene;
    mActiveSceneId = startScene->getSceneId();


    // game scene
    GameSceneImpl *gameScene = new GameSceneImpl();

    mScenes[gameScene->getSceneId()] = gameScene;

    // attach to active scene
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
