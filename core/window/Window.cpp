#include "include/global.hpp"

Window::Window(const WindowProperties &windowProperties)
{
    mWindowProperties = windowProperties;
    createWindow();
}

Window::~Window()
{
    SDL_DestroyRenderer(mSDLWindowRenderer);
    SDL_DestroyWindow(mSDLWindow);
    mSDLWindow = NULL;
    mSDLWindowRenderer = NULL;

    // TODO
    // SDL_Quit needs to be in proper shutdown sequence
}

bool Window::createWindow()
{
    SDL_Log("Window::createWindow windowName: %s screenHeight: %d screenWidth: %d \n",
            mWindowProperties.windowName.c_str(),
            mWindowProperties.screenHeight,
            mWindowProperties.screenWidth);

    if ( init() )
    {
        return true;
    }
    else
    {
        SDL_Log("Window::createWindow -- Failed to initialize the window");
        return false;
    }
}

SDL_Renderer * Window::getWindowRenderer()
{
    return mSDLWindowRenderer;
}

void Window::clearScreen()
{
    SDL_SetRenderDrawColor(mSDLWindowRenderer,
                           mSDLWindowProperties.bgColor.red,
                           mSDLWindowProperties.bgColor.green,
                           mSDLWindowProperties.bgColor.blue,
                           mSDLWindowProperties.bgColor.alpha);
    SDL_RenderClear(mSDLWindowRenderer);
}

void Window::updateScreen()
{
    SDL_RenderPresent(mSDLWindowRenderer);
}

bool Window::init()
{
    bool success = true;

    if ( SDL_Init(SDL_INIT_VIDEO) < 0 )
    {
        SDL_Log("Window::createWindow -- SDL could not initialize! SDL Error: %s", SDL_GetError());
        success = false;
    }
    else
    {
        // Set texture filtering to linear
        if ( !SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1") )
        {
            SDL_Log("Window::createWindow -- Warning: Linear texture filtering not enabled!");
        }

        // Create window
        mSDLWindow = SDL_CreateWindow(mSDLWindowProperties.windowName.c_str(),
                                      SDL_WINDOWPOS_UNDEFINED,
                                      SDL_WINDOWPOS_UNDEFINED,
                                      mSDLWindowProperties.screenWidth,
                                      mSDLWindowProperties.screenHeight,
                                      SDL_WINDOW_SHOWN);
        if ( mSDLWindow == NULL )
        {
            SDL_Log("Window::createWindow -- Window could not be created! SDL Error: %s", SDL_GetError());
            success = false;
        }
        else
        {
            // Create renderer for window
            mSDLWindowRenderer = SDL_CreateRenderer(mSDLWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if ( mSDLWindowRenderer == NULL )
            {
                SDL_Log("Window::createWindow -- Renderer could not be created! SDL Error: %s", SDL_GetError());
                success = false;
            }
            else
            {
                // Initialize renderer color
                SDL_SetRenderDrawColor(mSDLWindowRenderer,
                                       mSDLWindowProperties.bgColor.red,
                                       mSDLWindowProperties.bgColor.green,
                                       mSDLWindowProperties.bgColor.blue,
                                       mSDLWindowProperties.bgColor.alpha);
            }
        }
    }

    return success;
}
