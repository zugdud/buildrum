class InputEventTypeHandler
{

public:
InputEventTypeHandler();
~InputEventTypeHandler();

void registerObserver(SDL_EventType sdlEventType, InputEventTypeObserver *observer);
void pollEventQueue();

private:

std::map<SDL_EventType, InputEventTypeObserver *> mObservers;

};
