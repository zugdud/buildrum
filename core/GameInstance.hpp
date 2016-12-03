class GameInstance : public QuitEventObserver
{
public:

GameInstance();
~GameInstance();

bool init();
void showStartScreen();

private:

void setupStartScreen();
void quitEventCallback();

InputEventHandler mInputEventHandler;

UIMenu mMainMenu;
bool mRunning;

};
