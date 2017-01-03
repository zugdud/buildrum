class HandleNewGame : public IHandleEvent
{

public:

HandleNewGame(const std::string & eventId);
~HandleNewGame();

void handleEvent(IEventDispatch *eventManager);

private:

std::string mEventId;

};
