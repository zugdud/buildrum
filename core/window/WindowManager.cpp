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

SDL_Renderer * WindowManager::getSDLRenderer()
{
    return mWindow.getSDLWindowRenderer();
}

WindowManager * WindowManager::getInstance()
{
    if (!mSingletonInstance)
    {
        mSingletonInstance = new WindowManager;
    }
    return mSingletonInstance;
}

const Window & WindowManager::getWindow()
{
    return mWindow;
}

void WindowManager::registerObserver(WindowEventObserver *windowEventObserver)
{
    mObservers.push_back(windowEventObserver);
}

void WindowManager::switchActiveViewport(const std::string & viewportId)
{
    mActiveViewportId = viewportId;
    const SDL_Rect & viewportRect = getActiveViewport().getRect();
    const int result = SDL_RenderSetViewport(mWindow.getSDLWindowRenderer(), &viewportRect);
    if (result == -1)
    {
        SDL_Log("WindowManager::switchActiveViewport -- ERROR: setting viewportId: %s SDLError: %s \n", viewportId.c_str(), SDL_GetError());
    }
    else
    {
        // SDL_Log("WindowManager::switchActiveViewport -- viewportId: %s \n", viewportId.c_str());
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
    const std::vector<ViewContext> & viewContexts = mWindowPropertiesImpl.getViewContexts();

    for (size_t i = 0; i < viewContexts.size(); i++)
    {
        // Viewport viewport = Viewport(viewportProperties[i], mWindowPropertiesImpl.getWindowProperties());
        // mViewports.push_back(viewport);
    }
}
