#include "include/global.hpp"

WindowManager::WindowManager(const GameInstanceProperties &gameInstanceProperties)
{
    mGameInstanceProperties = gameInstanceProperties;
    createViewports();
    createWindow();
    SDL_Log("WindowManager::WindowManager -- Init Success. \n");
}

WindowManager::~WindowManager()
{

}

WindowManager::createViewports()
{
    std::vector<ViewportProperties> & viewportProperties = mGameInstanceProperties.getViewportProperties();

    for (size_t i = 0; i < viewportProperties.size(); i++)
    {
        mViewports.push_back(new Viewport(viewportProperties[i], mGameInstanceProperties.getWindowProperties()));
    }
}

WindowManager::createWindow()
{
    mWindow = new Window(mGameInstanceProperties.getWindowProperties());
}
