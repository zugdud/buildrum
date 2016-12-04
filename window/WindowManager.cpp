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

void WindowManager::setActiveViewContext(const std::string & viewContextId)
{
    mActiveViewContextId = viewContextId;
}
ViewContext & WindowManager::getActiveViewContext()
{
    return mViewContexts[mActiveViewContextId];
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

void WindowManager::configure(const WindowPropertiesImpl &windowPropertiesImpl)
{
    SDL_Log("---------------------------------------------------- \n");
    SDL_Log("WindowManager::configure -- Configuring... \n");
    mWindowPropertiesImpl = windowPropertiesImpl;
    mWindow.createWindow(mWindowPropertiesImpl.getWindowProperties());
    createViewContexts();
    SDL_Log("WindowManager::configure -- Configuring Success. \n");
    SDL_Log("---------------------------------------------------- \n");
}

void WindowManager::createViewContexts()
{
    const std::vector<ViewContextProperties> & viewContextProperties = mWindowPropertiesImpl.getViewContextProperties();

    for (size_t i = 0; i < viewContextProperties.size(); i++)
    {
        ViewContext viewContext;
        viewContext.configure(viewContextProperties[i],
                              mWindowPropertiesImpl.getWindowProperties(),
                              mWindow.getSDLWindowRenderer());
        mViewContexts.insert(std::pair<std::string, ViewContext>(viewContextProperties[i].viewContextId, viewContext) );
    }
}
