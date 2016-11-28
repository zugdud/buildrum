class WindowManager
{
public:

WindowManager(const GameInstanceProperties &gameInstanceProperties);
~WindowManager();

private:

void createViewports();
void createWindow();

GameInstanceProperties mGameInstanceProperties;
std::vector<Viewport *> mViewports;
Window *mWindow;

};
