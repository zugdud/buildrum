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
    RGBAColors red = { 255, 0, 0, 255 };
    RGBAColors green = { 0, 255, 0, 255 };
    RGBAColors blue = { 0, 0, 255, 255 };

    // viewportId, xPadRatio, yPadRatio, windowWidthRatio, bgColor, worldRenderingProperties, minimapRenderingProperties, menuRenderingProperties
    ViewportProperties actionMenu = { "actionMenu", 0.0, 0.0, 0.8, 0.2, red };
    ViewportProperties minimap = { "minimap", 0.8, 0.0, 0.2, 0.2, green };
    ViewportProperties gameView = { "gameView", 0.0, 0.2, 1.0, 0.8, blue };
    ViewportProperties fullscreen = { "fullscreen", 0.0, 0.0, 1.0, 1.0, blue };

    // viewContextId, numViewports, viewports[]
    ViewContextProperties fullscreenContext;

    fullscreenContext.viewContextId = "MainMenu";
    fullscreenContext.numViewports = 1;
    fullscreenContext.viewports[0] = fullscreen;

    ViewContextProperties gameplayContext;
    gameplayContext.viewContextId = "GameScene";
    gameplayContext.numViewports = 3;
    gameplayContext.viewports[0] = actionMenu;
    gameplayContext.viewports[1] = minimap;
    gameplayContext.viewports[2] = gameView;

    mViewContextProperties.push_back(fullscreenContext);
    mViewContextProperties.push_back(gameplayContext);
}

void WindowPropertiesImpl::setWindowProfiles()
{
    RGBAColors white = { 255, 255, 255, 255 };

    // windowName, bgColor, screenWidth, screenHeight
    WindowProperties linuxProperties = { "Buildrum", white, 1280, 960 };
    WindowProperties macProperties = { "Buildrum", white, 1024, 768 };
    WindowProperties androidProperties = { "Buildrum", white, 1440, 2560 };


    switch (G_BUILD_PROFILE)
    {
        case LINUX_BUILD: mWindowProperties = linuxProperties; break;
        case MAC_BUILD: mWindowProperties = macProperties; break;
        case ANDROID_BUILD: mWindowProperties = androidProperties; break;
    }
}
