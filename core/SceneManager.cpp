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

}

void SceneManager::setActiveScene(const std::string & activeSceneId)
{
    mActiveSceneId = activeSceneId;
}

void SceneManager::updateActiveScene()
{
    mScenes[mActiveSceneId]->update();
}
