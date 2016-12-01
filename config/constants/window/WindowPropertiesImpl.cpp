#include "include/global.hpp"

WindowPropertiesImpl::WindowPropertiesImpl()
{

}

WindowPropertiesImpl::~WindowPropertiesImpl()
{

}

void WindowPropertiesImpl::loadAll()
{
    setViewports();
    setWindowProfiles();
}

const std::vector<mViewContextProperties> & WindowPropertiesImpl::getViewContextProperties() const
{
    return mViewContextProperties;
}

const WindowProperties & WindowPropertiesImpl::getWindowProperties()
{
    return mWindowProperties["linux"];
}

void WindowPropertiesImpl::setViewContexts()
{
    mViewContexts.clear();

    RGBAColors red = { 255, 0, 0, 255 };
    RGBAColors green = { 0, 255, 0, 255 };
    RGBAColors blue = { 0, 0, 255, 255 };

    // RenderingProperties useRenderer, numLayerIds, layerIds
    RenderingProperties noRender;
    noRender.useRenderer = false;
    noRender.numLayers = 0;

    RenderingProperties fullscreen_menu_RP;
    fullscreen_menu_RP.useRenderer = true;
    fullscreen_menu_RP.numLayers = 1;
    fullscreen_menu_RP[0] = "MainMenu";

    // viewportId, xPadRatio, yPadRatio, windowWidthRatio, bgColor, worldRenderingProperties, minimapRenderingProperties, menuRenderingProperties
    ViewportProperties actionMenu = { "actionMenu", 0.0, 0.0, 0.8, 0.2, red, noRender, noRender, noRender };
    ViewportProperties minimap = { "minimap", 0.8, 0.0, 0.2, 0.2, green, noRender, noRender, noRender };
    ViewportProperties gameView = { "gameView", 0.0, 0.2, 1.0, 0.8, blue, noRender, noRender, noRender };
    ViewportProperties fullscreen = { "fullscreen", 0.0, 0.0, 1.0, 1.0, blue, noRender, noRender, fullscreen_menu_RP };

    // viewContextId, numViewports, viewports[]
    ViewContextProperties fullscreenContext;
    fullscreenContext.viewContextId = "start";
    fullscreenContext.numViewports = 1;
    fullscreenContext.viewports[0] = fullscreen;

    ViewContextProperties gameplayContext;
    gameplayContext.viewContextId = "gameplay";
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
    WindowProperties androidProperties = { "Buildrum", white, 1280, 760 };

    mWindowProperties["linux"] = linuxProperties;
    mWindowProperties["mac"] = macProperties;
    mWindowProperties["android"] = androidProperties;
}
