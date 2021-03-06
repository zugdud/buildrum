#include "include/global.hpp"

GameInstance::GameInstance()
{
    mObserverId = "GameInstance";
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
    EventManager::getInstance()->registerObserver(this);
    InputEventManager::getInstance()->registerQuitEventObserver(this);
    mRunning  = true;

    while ( mRunning )
    {
        InputEventManager::getInstance()->update();
        SceneManager::getInstance()->updateActiveScene();
    }
    shutdown();
}

void GameInstance::shutdown()
{
    SDL_Log("==================================================== \n");
    SDL_Log("GameInstance::shutdown -- shutting down... \n");
    SDL_Quit();
    SDL_Log("GameInstance::shutdown -- shutdown complete, exiting... \n");
    SDL_Log("==================================================== \n");
    std::exit(0);
}

void GameInstance::eventRaised(const std::string & eventId)
{
    SDL_Log("GameInstance::eventRaised -- eventId: %s \n", eventId.c_str());
    if (eventId == "exitGame")
    {
        mRunning = false;
    }
}

const std::string & GameInstance::getId()
{
    return mObserverId;
}

void GameInstance::quitEventCallback()
{
    SDL_Log("GameInstance::quitEventCallback \n");
    mRunning = false;
}
