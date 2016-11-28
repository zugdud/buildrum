#include "include/global.hpp"

GameInstanceProperties::GameInstanceProperties()
{
    setViewports();
    setWindowProfiles();
}

GameInstanceProperties::~GameInstanceProperties()
{

}

const std::vector<ViewportProperties> & GameInstanceProperties::getViewportProperties()
{
    return mViewportProperties;
}
const WindowProperties & GameInstanceProperties::getWindowProperties()
{
    return mWindowProperties["linux"];
}

void GameInstanceProperties::setViewports()
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

void GameInstanceProperties::setWindowProfiles()
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

void GameInstanceProperties::setInputTypeEvents()
{
    InputTypeEventProperties inputTypeEvent_exit = { "exit",  SDL_QUIT };
    InputTypeEventProperties inputTypeEvent_windowChange = { "windowChange",  SDL_WindowEvent };

    mInputTypeEventProperties.push_back(inputTypeEvent_exit);
    mInputTypeEventProperties.push_back(inputTypeEvent_windowChange);
}

void GameInstanceProperties::initInputPointEvents()
{
    SDL_Rect nullTriggerEventRect = { -1, -1, -1, -1 };

    mInputPointEventProperties[] =;
}

void GameInstanceProperties::updateInputPointEvents()
{
    //
}

struct InputTypeEventProperties
{
    std::string TypeEventName;
    SDL_EventType sdlEventType;
}

struct InputKeyEventProperties
{
    std::string KeyEventName;
    SDL_Keycode sdlKeyCode;
}

struct InputPointEventProperties
{
    std::string pointEventName;
    std::string viewportId;
    SDL_Rect triggerEventRect;
}

struct InputScrollEventProperties
{
    std::string scrollEventName;
    std::string viewportId;
    double scaleFactor;
    double minScrollRate;
    double maxScrollRate;
}
