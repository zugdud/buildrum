#include "include/global.hpp"

WindowManager *WindowManager::mSingletonInstance = 0;

WindowManager::WindowManager()
{
    // mWindow = Window();
    // mWindowPropertiesImpl = WindowPropertiesImpl();
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

void WindowManager::registerObserver(WindowEventObserver *windowEventObserver)
{
    mObservers.push_back(windowEventObserver);
}

void WindowManager::switchActiveViewport(const std::string & viewportId)
{
    mActiveViewportId = viewportId;
    const SDL_Rect & viewportRect = getActiveViewport().getRect();
    const int result = SDL_RenderSetViewport(mWindow.getWindowRenderer(), &viewportRect);
    if (result == -1)
    {
        SDL_Log("Error setting viewportId: %s SDLError: %s \n", viewportId.c_str(), SDL_GetError());
    }
}

void WindowManager::notifyObservers()
{
    for (size_t i = 0; i < mObservers.size(); i++)
    {
        mObservers[i]->viewportSwitchEvent(getActiveViewport());
    }
}

const Viewport & WindowManager::getViewport(const std::string & viewportId) const
{
    for (size_t i = 0; i < mViewports.size(); i++)
    {
        if (mViewports[i].isViewport(viewportId))
        {
            return mViewports[i];
        }
    }
    return mViewports[0];
}

const Viewport & WindowManager::getActiveViewport() const
{
    return getViewport(mActiveViewportId);
}

void WindowManager::configure(const WindowPropertiesImpl &windowPropertiesImpl)
{
    SDL_Log("---------------------------------------------------- \n");
    SDL_Log("WindowManager::configure -- Configuring... \n");
    mWindowPropertiesImpl = windowPropertiesImpl;
    mWindow.createWindow(mWindowPropertiesImpl.getWindowProperties());
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
