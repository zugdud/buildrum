class WindowManager
{

static WindowManager *mSingletonInstance;

public:

static WindowManager * getInstance();

void configure(const WindowPropertiesImpl &windowPropertiesImpl);

const Window & getWindow();
SDL_Renderer * getSDLRenderer();

ViewContext &getViewContext(const std::string & viewContextId);

private:

WindowManager();
~WindowManager();

void notifyObservers();
void createViewContexts();

WindowPropertiesImpl mWindowPropertiesImpl;

std::map<std::string, ViewContext> mViewContexts;

Window mWindow;

};
