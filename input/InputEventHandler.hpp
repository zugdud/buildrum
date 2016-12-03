class InputEventHandler
{

public:
InputEventHandler();
~InputEventHandler();

void registerObserver(InputEventObserver *observer);
void pollEventQueue();

private:

std::vector<InputEventObserver *> mObservers;

};
