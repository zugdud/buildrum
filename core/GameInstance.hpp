class GameInstance : public QuitEventObserver
{
public:

GameInstance();
~GameInstance();

bool init();
void run();

private:

void quitEventCallback();

bool mRunning;

};
