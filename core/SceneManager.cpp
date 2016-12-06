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
