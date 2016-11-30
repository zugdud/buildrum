class GameInstance : public InputEventTypeObserver
{
public:

GameInstance();
~GameInstance();

void init();
void start();
void run();

private:

void inputEventTypeCallback(SDL_EventType sdlEventType);

InputEventTypeHandler *mInputEventTypeHandler;

UIMenu mMainMenu;
bool mRunning;

};
