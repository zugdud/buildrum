class ViewContext
{
public:

ViewContext();
~ViewContext();

void configure(ViewContextProperties ViewContextProperties,
               const WindowProperties & windowProperties,
               SDL_Renderer *sdlRenderer);

const std::vector<Viewport> & getViewports();

private:

ViewContextProperties mViewContextProperties;
std::vector<Viewport> mViewports;

};
