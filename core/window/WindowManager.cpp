#include "include/global.hpp"

WindowManager *WindowManager::mSingletonInstance = 0;

WindowManager::WindowManager()
{

}

WindowManager::~WindowManager()
{

}

WindowManager * WindowManager::getInstance()
{
    if (!mSingletonInstance)
    {
        mSingletonInstance = new WindowManager;
    }
    return mSingletonInstance;
}

const Viewport & getViewport(const std::string & viewportId)
{
    for (size_t i = 0; i < mViewports.size(); i++)
    {
        if (mViewports[i].isViewport(viewportId))
        {
            return mViewports[i];
        }
    }
}

void WindowManager::configure(const WindowPropertiesImpl &windowPropertiesImpl)
{
    SDL_Log("---------------------------------------------------- \n");
    SDL_Log("WindowManager::configure -- Configuring... \n");
    mWindowPropertiesImpl = windowPropertiesImpl;
    createWindow();
    createViewports();
    SDL_Log("WindowManager::configure -- Configuring Success. \n");
    SDL_Log("---------------------------------------------------- \n");
}

void WindowManager::createViewports()
{
    const std::vector<ViewportProperties> & viewportProperties = mWindowPropertiesImpl.getViewportProperties();

    for (size_t i = 0; i < viewportProperties.size(); i++)
    {
        Viewport viewport = Viewport(viewportProperties[i], mWindowPropertiesImpl.getWindowProperties());
        mViewports.push_back(viewport);
    }
}

void WindowManager::createWindow()
{
    mWindow = Window(mWindowPropertiesImpl.getWindowProperties());
}
