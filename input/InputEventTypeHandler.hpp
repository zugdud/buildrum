class InputEventTypeHandler
{

public:
InputEventHandler();
~InputEventHandler();

private:

std::map<SDL_EventType, InputEventTypeObserver *> mObservers;

};
