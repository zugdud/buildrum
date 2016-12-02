class WindowManager
{

static WindowManager *mSingletonInstance;

public:

static WindowManager * getInstance();

void configure(const WindowPropertiesImpl &windowPropertiesImpl);
void registerObserver(WindowEventObserver *windowEventObserver);

const Window & getWindow();
SDL_Renderer * getSDLRenderer();

void setActiveViewContext(const std::string & viewContextId);
const ViewContext &getActiveViewContext() const;

private:

WindowManager();
~WindowManager();

void notifyObservers();
void createViewContexts();

std::string mActiveViewContextId;

WindowPropertiesImpl mWindowPropertiesImpl;
std::vector<WindowEventObserver * > mObservers;

std::map<std::string, ViewContext> mViewContexts;

Window mWindow;

};
