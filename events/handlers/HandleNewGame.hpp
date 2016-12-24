class HandleNewGame : public IHandleEvent
{

public:

HandleNewGame(const std::string & eventId);
~HandleNewGame();

void handleEvent();

private:

std::string mEventId;

};
