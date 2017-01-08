#include "include/global.hpp"

Viewport::Viewport()
{
    SDL_Log("Viewport::Viewport -- New Viewport \n");
    mWorldRenderer = NULL;
    mMinimapRenderer = NULL;
    mSelectedActionMenuRenderer = NULL;
    mStatusMenuRenderer = NULL;
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

    // update menu envelopes
    std::vector<UIMenu *> & layers = renderer->getAllLayers();
    for (size_t i = 0; i < layers.size(); i++)
    {
        if (layers[i]->getIMenuProperties()->getUIMenuProperties().viewportId == mViewportProperties.viewportId)
        {
            // const SDL_Rect envelopeRect = { 0, 0, mViewport.w, mViewport.h };
            SDL_Log("Viewport::addRenderer -- Updating Menu envelope to match assigned viewport. uiMenuId: %s viewportId: %s \n",
                    layers[i]->getIMenuProperties()->getUIMenuProperties().uiMenuId.c_str(),
                    mViewportProperties.viewportId.c_str());
            layers[i]->updateEnvelope(mViewport);
        }
        else
        {
            SDL_Log("Viewport::addRenderer -- skipping menu not set for this viewport. uiMenuId: %s viewportId: %s \n",
                    layers[i]->getIMenuProperties()->getUIMenuProperties().uiMenuId.c_str(),
                    mViewportProperties.viewportId.c_str());
        }
    }

    // update world renderer
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
    setRenderedViewport();

    // TODO move
    TimerManager::Instance().checkTimers();

    if (mWorldRenderer != NULL)
    {
        mWorldRenderer->renderWorld();
    }
    else if (mMinimapRenderer != NULL)
    {
        mMinimapRenderer->render();
    }
    else if (mSelectedActionMenuRenderer != NULL)
    {
        mSelectedActionMenuRenderer->render();
    }
    else if (mStatusMenuRenderer != NULL)
    {
        mStatusMenuRenderer->render();
    }

    // draw menus
    for (size_t i = 0; i < mRenderers.size(); i++)
    {
        mRenderers[i]->renderAllLayers(mViewportProperties.viewportId);
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

const SDL_Rect &  Viewport::getRect() const
{
    return mViewport;
}

const ViewportProperties & Viewport::getViewportProperties() const
{
    return mViewportProperties;
}

void Viewport::detatchWorldRenderer()
{
    mWorldRenderer = NULL;
    SDL_Log("Viewport::detatchWorldRenderer -- detatched from world renderer (no longer invoking render) \n");
}

void Viewport::detatchMinimapRenderer()
{
    mMinimapRenderer = NULL;
    SDL_Log("Viewport::detatchMinimapRenderer -- detatched from minimap renderer (no longer invoking render) \n");
}

void Viewport::detatchStatusMenuRenderer()
{
    mStatusMenuRenderer = NULL;
    SDL_Log("Viewport::detatchStatusMenuRenderer -- detatched from statusMenuRenderer renderer (no longer invoking render) \n");
}

void Viewport::detatchSelectedActionRenderer()
{
    mSelectedActionMenuRenderer = NULL;
    SDL_Log("Viewport::detatchSelectedActionRenderer -- detatched from minimap renderer (no longer invoking render) \n");
}

void Viewport::attachWorldRenderer(IWorldRenderer *worldRenderer)
{
    mWorldRenderer = worldRenderer;
    SDL_Log("Viewport::attachWorldRenderer -- attached to worldRenderer. \n");
}

void Viewport::attachMinimapRenderer(IMinimapRenderer *minimapRenderer)
{
    mMinimapRenderer = minimapRenderer;
    SDL_Log("Viewport::attachMinimapRenderer -- attached to minimapRenderer. \n");
}

void Viewport::attachSelectedActionMenuRenderer(IRendererSelectedAction *selectedActionRenderer)
{
    mSelectedActionMenuRenderer = selectedActionRenderer;
    SDL_Log("Viewport::attachSelectedActionMenuRenderer -- attached to selectedActionRenderer. \n");
}

void Viewport::attachStatusMenuRenderer(IStatusMenuRenderer *statusMenuRenderer)
{
    mStatusMenuRenderer = statusMenuRenderer;
    SDL_Log("Viewport::attachStatusMenuRenderer -- attached to statusMenuRenderer. \n");
}
