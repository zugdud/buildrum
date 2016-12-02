class ViewContext
{
public:

ViewContext();
~ViewContext();

void configure(ViewContextProperties ViewContextProperties,
               const WindowProperties & windowProperties,
               SDL_Renderer *sdlRenderer);

std::vector<Viewport> & getViewports();

private:

ViewContextProperties mViewContextProperties;
std::vector<Viewport> mViewports;

};
