class InputEventHandler
{

public:
InputEventHandler();
~InputEventHandler();

void registerQuitEventObserver(QuitEventObserver *quitEventObserver);
void registerTouchEventObserver(TouchEventObserver *touchEventObserver);

void pollEventQueue();

private:

std::vector<QuitEventObserver *> mQuitEventObservers;
std::vector<TouchEventObserver *> mTouchEventObserver;

};
