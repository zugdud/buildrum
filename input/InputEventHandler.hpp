class InputEventHandler
{

public:
InputEventHandler();
~InputEventHandler();

void registerQuitEventObserver(QuitEventObserver *quitEventObserver);
void registerPointEventObserver(PointEventObserver *pointEventObserver);

void pollEventQueue();

private:

void dispatchPointEvent(const SDL_Event & sdlEvent);

std::vector<QuitEventObserver *> mQuitEventObservers;
std::vector<PointEventObserver *> mPointEventObserver;

};
