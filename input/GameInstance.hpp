class GameInstance
{
public:

GameInstance();
~GameInstance();

void run();

private:

GameInstanceProperties *mGameInstanceProperties;
WindowManager *mWindowManager;
};
