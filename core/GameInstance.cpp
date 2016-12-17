#include "include/global.hpp"

GameInstance::GameInstance()
{

}

GameInstance::~GameInstance()
{

}

bool GameInstance::init()
{

    SDL_Log("==================================================== \n");
    SDL_Log("GameInstance::init -- setting up manager instances... \n");
    // ConfigManager
    ConfigManager::getInstance()->loadConstants();

    // WindowManager
    WindowManager::getInstance()->configure(ConfigManager::getInstance()->getWindowPropertiesImpl());

    // MenuManager
    MenuManager::Instance().configure();

    // FontManager
    if (!FontManager::getInstance()->configure(ConfigManager::getInstance()->getEnvironmentMediaPropertiesImpl(),
                                               ConfigManager::getInstance()->getFontProfileImpl()))
    {
        return false;
    }

    // Audio Manager
    if (!AudioManager::Instance().configure(ConfigManager::getInstance()->getEnvironmentMediaPropertiesImpl(),
                                            ConfigManager::getInstance()->getAudioContentImpl()))
    {
        return false;
    }

    // Sprite Sheet Manager
    if (!SpriteSheetManager::Instance().configure(ConfigManager::getInstance()->getEnvironmentMediaPropertiesImpl(),
                                                  ConfigManager::getInstance()->getSpriteSheetPropertiesImpl()))
    {
        return false;
    }

    // Event mAudioManager
    EventManager::getInstance()->configure(&AudioManager::Instance());

    // scenemanaager
    SceneManager::getInstance()->init();

    // camera
    Camera::Instance().configure(ConfigManager::getInstance()->getCameraPropertiesImpl().getCameraProperties());

    // world
    // WorldManager::Instance();

    SDL_Log("==================================================== \n");
    return true;
}

void GameInstance::run()
{
    InputEventManager::getInstance()->registerQuitEventObserver(this);
    mRunning  = true;

    while ( mRunning )
    {
        InputEventManager::getInstance()->pollEventQueue();
        SceneManager::getInstance()->updateActiveScene();
    }
}

void GameInstance::quitEventCallback()
{
    mRunning = false;
}
