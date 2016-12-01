class GameInstance : public InputEventTypeObserver
{
public:

GameInstance();
~GameInstance();

bool init();
void run();

private:

void inputEventTypeCallback(SDL_EventType sdlEventType);

InputEventTypeHandler *mInputEventTypeHandler;

UIMenu mMainMenu;
bool mRunning;

};
