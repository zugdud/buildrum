class WindowManager
{

static WindowManager *mSingletonInstance;

public:

static WindowManager * getInstance();

void configure(const WindowPropertiesImpl &windowPropertiesImpl);

const Window & getWindow();
SDL_Renderer * getSDLRenderer();

void setActiveViewContext(const std::string & viewContextId);
ViewContext &getActiveViewContext();

private:

WindowManager();
~WindowManager();

void notifyObservers();
void createViewContexts();

std::string mActiveViewContextId;
WindowPropertiesImpl mWindowPropertiesImpl;

std::map<std::string, ViewContext> mViewContexts;

Window mWindow;

};
