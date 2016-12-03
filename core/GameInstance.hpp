class GameInstance : public InputEventObserver
{
public:

GameInstance();
~GameInstance();

bool init();
void showStartScreen();

private:

void setupStartScreen();
void inputEventCallback(InputEvent inputEvent);

InputEventHandler mInputEventHandler;

UIMenu mMainMenu;
bool mRunning;

};
