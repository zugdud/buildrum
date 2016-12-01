#include "include/global.hpp"

Viewport::Viewport()
{

}

Viewport::~Viewport()
{

}

void Viewport::configure(const ViewportProperties &viewportProperties,
                         const WindowProperties &windowProperties,
                         SDL_Renderer *sdlRenderer)
{
    mViewportProperties = viewportProperties;
    mSDLRenderer = sdlRenderer;
    setViewport(windowProperties);
}

void Viewport::setViewport(const WindowProperties &windowProperties)
{
    mViewport.x = windowProperties.screenWidth * mViewportProperties.xPadRatio;
    mViewport.y = windowProperties.screenHeight * mViewportProperties.yPadRatio;
    mViewport.w = windowProperties.screenWidth * mViewportProperties.windowWidthRatio;
    mViewport.h = windowProperties.screenHeight * mViewportProperties.windowHeightRatio;

    SDL_Log("Viewport::setViewport -- viewportId: %s x: %d y: %d w: %d h: %d \n",
            mViewportProperties.viewportId.c_str(),
            mViewport.x,
            mViewport.y,
            mViewport.w,
            mViewport.h);
}

void Viewport::setRenderedViewport()
{
    const int result = SDL_RenderSetViewport(mSDLRenderer, &mViewport);

    if (result == -1)
    {
        SDL_Log("Viewport::setRenderedViewport -- ERROR: setting viewportId: %s SDLError: %s \n", mViewportProperties.viewportId.c_str(), SDL_GetError());
    }
    else
    {
        SDL_Log("WindowManager::setRenderedViewport -- viewportId: %s \n", mViewportProperties.viewportId.c_str());
    }
}
