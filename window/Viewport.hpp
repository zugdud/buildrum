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
void removeAllRenderers();
void renderUpdate() const;

void detatchWorldRenderer();
void detatchMinimapRenderer();
void detatchSelectedActionRenderer();
void detatchStatusMenuRenderer();

void attachWorldRenderer(IWorldRenderer *worldRenderer);
void attachMinimapRenderer(IMinimapRenderer *minimapRenderer);
void attachSelectedActionMenuRenderer(IRendererSelectedAction *selectedActionRenderer);
void attachStatusMenuRenderer(IStatusMenuRenderer *statusMenuRenderer);

const SDL_Rect & getRect() const;

private:

void positionViewport(const WindowProperties &windowProperties);
void setRenderedViewport() const;

ViewportProperties mViewportProperties;
SDL_Rect mViewport;
SDL_Renderer *mSDLRenderer;

std::vector<IRenderer *> mRenderers;
IWorldRenderer *mWorldRenderer;
IMinimapRenderer *mMinimapRenderer;
IRendererSelectedAction *mSelectedActionMenuRenderer;
IStatusMenuRenderer *mStatusMenuRenderer;

};
