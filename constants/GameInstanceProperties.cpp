#include "include/global.hpp"

GameInstanceProperties::GameInstanceProperties()
{
    setViewports();
    setWindowProfiles();
}

GameInstanceProperties::~GameInstanceProperties()
{

}

const std::vector & getViewportProperties()
{
    return mViewportProperties;
}
const WindowProperties & getWindowProperties()
{
    return mWindowProperties["linux"];
}

void GameInstanceProperties::setViewports()
{
    mViewportProperties.clear();

    RGBAColors red = { 255, 0, 0, 255 };
    RGBAColors green = { 0, 255, 0, 255 };
    RGBAColors blue = { 0, 0, 255, 255 };

    ViewportProperties actionMenu;
    ViewportProperties minimap;
    ViewportProperties gameView;
    ViewportProperties fullscreen;

    actionMenu.viewportId = "actionMenu";
    actionMenu.xPadRatio = 0.0;
    actionMenu.xPadRatio = 0.0;
    actionMenu.windowWidthRatio = 0.8;
    actionMenu.windowHeightRatio = 0.2;
    actionMenu.bgColor = red;

    minimap.viewportId = "minimap";
    minimap.xPadRatio = 0.8;
    minimap.yPadRatio = 0.0;
    minimap.windowWidthRatio = 0.2;
    minimap.windowHeightRatio = 0.2;
    minimap.bgColor = green;

    gameView.viewportId = "gameView";
    gameView.xPadRatio = 0.0;
    gameView.yPadRatio = 0.2;
    gameView.windowWidthRatio = 1.0;
    gameView.windowHeightRatio = 0.8;
    gameView.bgColor = blue;

    fullscreen.viewportId = "fullscreen";
    fullscreen.xPadRatio = 0.0;
    fullscreen.yPadRatio = 0.0;
    fullscreen.windowWidthRatio = 1.0;
    fullscreen.windowHeightRatio = 1.0;
    fullscreen.bgColor = blue;

    mViewportProperties.push_back(actionMenu);
    mViewportProperties.push_back(minimap);
    mViewportProperties.push_back(gameView);
    mViewportProperties.push_back(fullscreen);
}

void GameInstanceProperties::setWindowProfiles()
{
    RGBAColors white = { 255, 255, 255, 255 };

    WindowProperties linux;
    WindowProperties mac;
    WindowProperties android;

    linux.windowName = "Buildrum";
    linux.bgColor = white;
    linux.screenWidth = 1280;
    linux.screenHeight = 960;

    mac.windowName = "Buildrum";
    mac.bgColor = white;
    mac.screenWidth = 1280;
    mac.screenHeight = 960;

    android.windowName = "Buildrum";
    android.bgColor = white;
    android.screenWidth = 1280;
    android.screenHeight = 720;

    mWindowProperties["linux"] = linux;
    mWindowProperties["mac"] = mac;
    mWindowProperties["android"] = android;
}
