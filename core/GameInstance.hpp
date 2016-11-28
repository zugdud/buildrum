class GameInstance
{
public:

GameInstance();
~GameInstance();

void init();

private:

GameInstanceProperties *mGameInstanceProperties;
WindowManager *mWindowManager;
};
