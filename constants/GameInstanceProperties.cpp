#include "include/global.hpp"

GameInstanceProperties::GameInstanceProperties()
{
    setViewports();
    setWindowProfiles();
    setCamera();
}

GameInstanceProperties::~GameInstanceProperties()
{

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

    actionMenu.viewportId = "actionMenu";
    actionMenu.xPositionOffsetRatio = 0.0;
    actionMenu.yPositionOffsetRatio = 0.0;
    actionMenu.windowWidthRatio = 0.8;
    actionMenu.windowHeightRatio = 0.2;
    actionMenu.bgColor = red;

    minimap.viewportId = "minimap";
    minimap.xPadRatio = 0.0;
    minimap.yPadRatio = 0.8;
    minimap.windowWidthRatio = 1.0;
    minimap.windowHeightRatio = 1.0;
    minimap.bgColor = green;

    gameView.viewportId = "gameView";
    gameView.xPadRatio = 0.0;
    gameView.yPadRatio = 0.2;
    gameView.windowWidthRatio = 1.0;
    gameView.windowHeightRatio = 1.0;
    gameView.bgColor = blue;

    mViewportProperties.push_back(actionMenu);
    mViewportProperties.push_back(minimap);
    mViewportProperties.push_back(gameView);
}

void GameInstanceProperties::setWindowProfiles()
{
    WindowProperties linux;
    WindowProperties mac;
    WindowProperties android;

    linux.screenWidth = 1280;
    linux.screenHeight = 960;

    mac.screenWidth = 1280;
    mac.screenHeight = 960;

    android.screenWidth = 1280;
    android.screenHeight = 720;

    mWindowProperties["linux"] = linux;
    mWindowProperties["mac"] = mac;
    mWindowProperties["android"] = android;
}

void GameInstanceProperties::setCamera()
{
    mCameraProperties.defaultZoomLevel = 1.0;
    mCameraProperties.maxZoomLevel = 4.0;
    mCameraProperties.minZoomLevel = 0.2;
}
