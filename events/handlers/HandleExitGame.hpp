class HandleExitGame : public IHandleEvent
{

public:

HandleExitGame(const std::string & eventId);
~HandleExitGame();

void handleEvent(IEventDispatch *eventManager);

private:

std::string mEventId;

};
