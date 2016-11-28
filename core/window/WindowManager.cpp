#include "include/global.hpp"

WindowManager::WindowManager(const GameInstanceProperties &gameInstanceProperties)
{
    mGameInstanceProperties = gameInstanceProperties;
    createWindow();
    createViewports();
    SDL_Log("WindowManager::WindowManager -- Init Success. \n");
}

WindowManager::~WindowManager()
{

}

void WindowManager::createViewports()
{
    const std::vector<ViewportProperties> & viewportProperties = mGameInstanceProperties.getViewportProperties();

    for (size_t i = 0; i < viewportProperties.size(); i++)
    {
        mViewports.push_back(new Viewport(viewportProperties[i], mGameInstanceProperties.getWindowProperties()));
    }
}

void WindowManager::createWindow()
{
    mWindow = new Window(mGameInstanceProperties.getWindowProperties());
}
