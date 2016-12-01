class WindowManager
{

static WindowManager *mSingletonInstance;

public:

static WindowManager * getInstance();

void configure(const WindowPropertiesImpl &windowPropertiesImpl);
void registerObserver(WindowEventObserver *windowEventObserver);

const Window & getWindow();
SDL_Renderer * getSDLRenderer();

void switchActiveViewport(const std::string & viewportId);
const Viewport &getActiveViewport() const;
const Viewport &getViewport(const std::string & viewportId) const;

private:

WindowManager();
~WindowManager();

void notifyObservers();
void createViewports();

std::string mActiveViewportId;
ViewContext mActiveViewContextId;

WindowPropertiesImpl mWindowPropertiesImpl;
std::vector<Viewport> mViewports;
std::vector<WindowEventObserver * > mObservers;

Window mWindow;

};
