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

bool SceneManager::init()
{

    // start scene
    IScene *startScene = new StartSceneImpl();

    mScenes[startScene->getSceneId()] = startScene;
    mActiveSceneId = startScene->getSceneId();

    // game scene

}

void SceneManager::setActiveScene(const std::string & activeSceneId)
{
    mActiveSceneId = activeSceneId;
    WindowManager::getInstance()->setActiveViewContext(mActiveSceneId);
}

void GameInstance::updateActiveScene()
{
    mScenes[mActiveSceneId].update();
}
