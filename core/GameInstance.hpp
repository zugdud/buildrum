class GameInstance : public InputEventTypeObserver
{
public:

GameInstance();
~GameInstance();

void run();

private:

void inputEventTypeCallback(SDL_EventType sdlEventType);

WindowManager *mWindowManager;
InputEventTypeHandler *mInputEventTypeHandler;

bool mRunning;

};
