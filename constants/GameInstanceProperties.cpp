#include "include/global.hpp"

GameInstanceProperties::GameInstanceProperties()
{

}

GameInstanceProperties::~GameInstanceProperties()
{

}

void GameInstanceProperties::setWindowProperties()
{
    ViewportProperties actionMenu;

    actionMenu.viewportId = "actionMenu";
    actionMenu.xPositionOffset = 0;
    actionMenu.yPositionOffset = 0;
    actionMenu.windowWidthRatio = 0.8;
    actionMenu.windowHeightRatio = 0.2;

    ViewportProperties gameView;

    gameView.viewportId = "gameView";
    gameView.xPositionOffset = 0;
    gameView.yPositionOffset = 0;
    gameView.windowWidthRatio = 1.0;
    gameView.windowHeightRatio = 0.2;

    ViewportProperties actionMenuViewport;

    actionMenuViewport.viewportId = "actionMenu";
    actionMenuViewport.xPositionOffset = 0;
    actionMenuViewport.yPositionOffset = 0;
    actionMenuViewport.windowWidthRatio = 0.8;
    actionMenuViewport.windowHeightRatio = 0.2;


    std::string viewportId;


    int xPositionOffset;
    int yPositionOffset;
    double windowWidthRatio;
    double windowHeightRatio;
}

void GameInstanceProperties::setWindowProperties(ViewportProperties viewport)
{

}

struct WindowProperties
{
    int screenHeight;
    int screenWidth;
    int numViewports;
    ViewportProperties Viewports[arraySize];
    std::string windowId;
};

struct ViewportProperties
{
    std::string viewportId;
    int xPositionOffset;
    int yPositionOffset;
    double windowWidthRatio;
    double windowHeightRatio;
};

struct CameraProperties
{
    int levelWidth;
    int levelHeight;
    double defaultZoomLevel;
    double maxZoomLevel;
    double minZoomLevel;
};
