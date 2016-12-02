class Viewport
{
public:

Viewport();
~Viewport();

const ViewportProperties & getViewportProperties() const;

void configure(const ViewportProperties &viewportProperties,
               const WindowProperties &windowProperties,
               SDL_Renderer *sdlRenderer);

void addRenderer(IRenderer *renderer);
void renderUpdate() const;


private:

void positionViewport(const WindowProperties &windowProperties);
void registerObserver(ViewportObserver *viewportObserver);
void setRenderedViewport() const;

ViewportProperties mViewportProperties;
SDL_Rect mViewport;
SDL_Renderer *mSDLRenderer;

std::vector<ViewportObserver *> mObservers;
std::vector<IRenderer *> mRenderers;
};
