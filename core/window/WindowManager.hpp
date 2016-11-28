class WindowManager
{
public:

WindowManager();
~WindowManager();

private:

GameInstanceProperties mGameInstanceProperties;
std::vector<Viewport *> mViewports;
Window *mWindow;

};
