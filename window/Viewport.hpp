class Viewport
{
public:

Viewport();
~Viewport();

const ViewportProperties & getViewportProperties() const;
void setRenderedViewport();

void configure(const ViewportProperties &viewportProperties,
               const WindowProperties &windowProperties,
               SDL_Renderer *sdlRenderer);


private:

void setViewport(const WindowProperties &windowProperties);

ViewportProperties mViewportProperties;
SDL_Rect mViewport;
SDL_Renderer *mSDLRenderer;
};
