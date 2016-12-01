class WindowManager
{

static WindowManager *mSingletonInstance;

public:

static WindowManager * getInstance();

void configure(const WindowPropertiesImpl &windowPropertiesImpl);
void registerObserver(WindowEventObserver *windowEventObserver);

const Window & getWindow();
SDL_Renderer * getSDLRenderer();

void setActiveViewContext(const ViewContext & viewContext);
const ViewContext &getActiveViewContext() const;

private:

WindowManager();
~WindowManager();

void notifyObservers();
void createViewContexts();

ViewContext mActiveViewContext;

WindowPropertiesImpl mWindowPropertiesImpl;
std::vector<ViewContext> mViewContexts;
std::vector<WindowEventObserver * > mObservers;

Window mWindow;

};
