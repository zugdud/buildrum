class GameInstance : public QuitEventObserver
{
public:

GameInstance();
~GameInstance();

bool init();
void showStartScreen();
void showGameScene();

private:

void setupStartScreen();
void setupGameScene();
void quitEventCallback();

InputEventHandler mInputEventHandler;

UIMenu mMainMenu;
bool mRunning;

};
