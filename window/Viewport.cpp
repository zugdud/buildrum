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
    positionViewport(windowProperties);
}

void Viewport::positionViewport(const WindowProperties &windowProperties)
{
    mViewport.x = windowProperties.screenWidth * mViewportProperties.xPadRatio;
    mViewport.y = windowProperties.screenHeight * mViewportProperties.yPadRatio;
    mViewport.w = windowProperties.screenWidth * mViewportProperties.windowWidthRatio;
    mViewport.h = windowProperties.screenHeight * mViewportProperties.windowHeightRatio;

    SDL_Log("Viewport::positionViewport -- viewportId: %s x: %d y: %d w: %d h: %d \n",
            mViewportProperties.viewportId.c_str(),
            mViewport.x,
            mViewport.y,
            mViewport.w,
            mViewport.h);
}

void Viewport::addRenderer(IRenderer *renderer)
{
    SDL_Log("Viewport::addRenderer -- adding renderer to viewportId: %s \n", mViewportProperties.viewportId.c_str());
    mRenderers.push_back(renderer);

    // update envelopes
    std::vector<UIMenu *> & layers = renderer->getAllLayers();
    for (size_t i = 0; i < layers.size(); i++)
    {
        SDL_Log("Viewport::addRenderer -- viewportId: %s \n", mViewportProperties.viewportId.c_str());
        layers[i]->updateEnvelope(mViewport);
    }
}

void Viewport::removeAllRenderers()
{
    for (size_t i = 0; i < mRenderers.size(); i++)
    {
        SDL_Log("Viewport::removeRenderer -- removing renderer from viewportId: %s \n", mViewportProperties.viewportId.c_str());
        mRenderers.erase(mRenderers.begin() + i);
    }
}

void Viewport::renderUpdate() const
{
    for (size_t i = 0; i < mRenderers.size(); i++)
    {
        setRenderedViewport();
        mRenderers[i]->renderAllLayers();
    }
}

void Viewport::setRenderedViewport() const
{
    const int result = SDL_RenderSetViewport(mSDLRenderer, &mViewport);

    if (result == -1)
    {
        SDL_Log("Viewport::setRenderedViewport -- ERROR: setting viewportId: %s SDLError: %s \n", mViewportProperties.viewportId.c_str(), SDL_GetError());
    }
    else
    {
        // SDL_Log("WindowManager::setRenderedViewport -- viewportId: %s \n", mViewportProperties.viewportId.c_str());
    }
}
