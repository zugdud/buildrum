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

const std::vector<ViewportProperties> & WindowPropertiesImpl::getViewportProperties() const
{
    return mViewportProperties;
}
const WindowProperties & WindowPropertiesImpl::getWindowProperties()
{
    return mWindowProperties["linux"];
}

void WindowPropertiesImpl::setViewports()
{
    mViewportProperties.clear();

    RGBAColors red = { 255, 0, 0, 255 };
    RGBAColors green = { 0, 255, 0, 255 };
    RGBAColors blue = { 0, 0, 255, 255 };

    // viewportId, xPadRatio, yPadRatio, windowWidthRatio, bgColor
    ViewportProperties actionMenu = { "actionMenu", 0.0, 0.0, 0.8, 0.2, red };
    ViewportProperties minimap = { "minimap", 0.8, 0.0, 0.2, 0.2, green };
    ViewportProperties gameView = { "gameView", 0.0, 0.2, 1.0, 0.8, blue };
    ViewportProperties fullscreen = { "fullscreen", 0.0, 0.0, 1.0, 1.0, blue };

    mViewportProperties.push_back(actionMenu);
    mViewportProperties.push_back(minimap);
    mViewportProperties.push_back(gameView);
    mViewportProperties.push_back(fullscreen);
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
