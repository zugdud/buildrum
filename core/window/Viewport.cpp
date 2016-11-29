#include "include/global.hpp"

Viewport::Viewport(const ViewportProperties &viewportProperties, const WindowProperties &windowProperties)
{
    mViewportProperties = viewportProperties;
    setViewport(windowProperties);
}

Viewport::~Viewport()
{

}

bool isViewport(const std::string & viewportId)
{
    if (mViewportProperties.viewportId == viewportId)
    {
        return true;
    }
    return false;
}

const SDL_Rect & getRect()
{
    return mViewport;
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
