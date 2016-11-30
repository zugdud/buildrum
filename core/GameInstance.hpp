class GameInstance : public InputEventTypeObserver
{
public:

GameInstance();
~GameInstance();

void init();
void mainMenu();
void run();

private:

void inputEventTypeCallback(SDL_EventType sdlEventType);

InputEventTypeHandler *mInputEventTypeHandler;

UIMenu mMainMenu;
bool mRunning;
};
