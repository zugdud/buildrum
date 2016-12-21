#include "include/global.hpp"

WindowPropertiesImpl::WindowPropertiesImpl()
{

}

WindowPropertiesImpl::~WindowPropertiesImpl()
{

}

void WindowPropertiesImpl::loadAll()
{
    SDL_Log("MainMenuPropertiesImpl::loadAll -- loading configuration ...\n");
    setViewContexts();
    setWindowProfiles();
}

const std::vector<ViewContextProperties> & WindowPropertiesImpl::getViewContextProperties() const
{
    return mViewContextProperties;
}

const WindowProperties & WindowPropertiesImpl::getWindowProperties()
{
    return mWindowProperties;
}

void WindowPropertiesImpl::setViewContexts()
{
    SDL_Color red = { 255, 0, 0, 255 };
    SDL_Color green = { 0, 255, 0, 255 };
    SDL_Color blue = { 0, 0, 255, 255 };

    // struct ViewportProperties
    // {
    //     std::string viewportId;
    //     double xPadRatio;
    //     double yPadRatio;
    //     double windowWidthRatio;
    //     double windowHeightRatio;
    //     SDL_Color bgColor;
    // };

    #ifdef LINUX_BUILD_TARGET
    ViewportProperties actionMenu = { "actionMenu", 0.0, 0.0, 0.45, 0.2, red };
    ViewportProperties selectedAction = { "selectedAction", 0.0, 0.0, 0.15, 0.2, red };
    ViewportProperties statusMenu = { "statusMenu", 0.0, 0.0, 0.15, 0.2, red };
    ViewportProperties minimap = { "minimap", 0.85, 0.0, 0.15, 0.2, green };
    ViewportProperties gameView = { "gameView", 0.0, 0.2, 1.0, 0.8, blue };
    ViewportProperties fullscreen = { "fullscreen", 0.0, 0.0, 1.0, 1.0, blue };
    #endif

    #ifdef MAC_BUILD_TARGET
    ViewportProperties actionMenu = { "actionMenu", 0.0, 0.0, 0.85, 0.2, red };
    ViewportProperties minimap = { "minimap", 0.85, 0.0, 0.15, 0.2, green };
    ViewportProperties gameView = { "gameView", 0.0, 0.2, 1.0, 0.8, blue };
    ViewportProperties fullscreen = { "fullscreen", 0.0, 0.0, 1.0, 1.0, blue };
    #endif

    #ifdef ANDROID_BUILD_TARGET
    ViewportProperties actionMenu = { "actionMenu", 0.0, 0.0, 0.85, 0.09295, red };
    ViewportProperties minimap = { "minimap", 0.85, 0.0, 0.15, 0.09295, green };
    ViewportProperties gameView = { "gameView", 0.0, 0.09295, 1.0, 0.90705, blue };
    ViewportProperties fullscreen = { "fullscreen", 0.0, 0.0, 1.0, 1.0, blue };
    #endif

    #ifdef SQUARE_TEST_TARGET
    ViewportProperties actionMenu = { "actionMenu", 0.0, 0.0, 0.9, 0.1, red };
    ViewportProperties minimap = { "minimap", 0.9, 0.0, 0.1, 0.1, green };
    ViewportProperties gameView = { "gameView", 0.0, 0.1, 1.0, 0.9, blue };
    ViewportProperties fullscreen = { "fullscreen", 0.0, 0.0, 1.0, 1.0, blue };
    #endif

    // viewContextId, numViewports, viewports[]
    ViewContextProperties fullscreenContext;

    fullscreenContext.viewContextId = "MainMenu";
    fullscreenContext.numViewports = 1;
    fullscreenContext.viewports[0] = fullscreen;

    ViewContextProperties gameplayContext;
    gameplayContext.viewContextId = "GameScene";
    gameplayContext.numViewports = 5;
    gameplayContext.viewports[0] = actionMenu;
    gameplayContext.viewports[1] = selectedAction;
    gameplayContext.viewports[2] = statusMenu;
    gameplayContext.viewports[3] = gameView;
    gameplayContext.viewports[4] = minimap;

    mViewContextProperties.push_back(fullscreenContext);
    mViewContextProperties.push_back(gameplayContext);
}

void WindowPropertiesImpl::setWindowProfiles()
{
    SDL_Color white = { 255, 255, 255, 255 };

    // windowName, bgColor, screenWidth, screenHeight

    #ifdef LINUX_BUILD_TARGET
    WindowProperties linuxProperties = { "Buildrum", white, 1280, 960 };
    mWindowProperties = linuxProperties;
    #endif

    #ifdef MAC_BUILD_TARGET
    WindowProperties macProperties = { "Buildrum", white, 1024, 768 };
    mWindowProperties = macProperties;
    #endif

    #ifdef ANDROID_BUILD_TARGET
    WindowProperties androidProperties = { "Buildrum", white, 1440, 2560 };
    mWindowProperties = androidProperties;
    #endif

    #ifdef SQUARE_TEST_TARGET
    WindowProperties squareTestProperties = { "Buildrum", white, 1440, 1440 };
    mWindowProperties = squareTestProperties;
    #endif

}
