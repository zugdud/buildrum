class GameInstance : public InputEventTypeObserver
{
public:

GameInstance();
~GameInstance();

void run();

private:

void inputEventTypeCallback(SDL_EventType sdlEventType);

GameInstanceProperties *mGameInstanceProperties;
WindowManager *mWindowManager;

bool mRunning;

};
