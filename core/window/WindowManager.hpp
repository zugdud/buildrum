class WindowManager
{

static WindowManager *mSingletonInstance;

public:

static WindowManager * getInstance();

void configure(const WindowPropertiesImpl &mWindowPropertiesImpl);
const Viewport & getViewport(const std::string & viewportId);

private:

WindowManager();
~WindowManager();

void createViewports();
void createWindow();

WindowPropertiesImpl mWindowPropertiesImpl;
std::vector<Viewport> mViewports;
Window mWindow;

};
