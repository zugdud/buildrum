#include "include/global.hpp"

ViewContext::ViewContext()
{

}

ViewContext::~ViewContext()
{

}

std::vector<Viewport> & ViewContext::getViewports()
{
    return mViewports;
}

void ViewContext::configure(ViewContextProperties ViewContextProperties,
                            const WindowProperties &windowProperties,
                            SDL_Renderer *sdlRenderer)
{
    SDL_Log("----------------------- \n");

    mViewContextProperties = ViewContextProperties;
    SDL_Log("ViewContext::configure -- Configuring viewContextId %s \n", mViewContextProperties.viewContextId.c_str());

    for (int i = 0; i < mViewContextProperties.numViewports; i++)
    {
        Viewport viewport;
        viewport.configure(mViewContextProperties.viewports[i], windowProperties, sdlRenderer);
        mViewports.push_back(viewport);
    }
    SDL_Log("----------------------- \n");
}
