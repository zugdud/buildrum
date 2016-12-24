class HandleExitGame : public IHandleEvent
{

public:

HandleExitGame(const std::string & eventId);
~HandleExitGame();

void handleEvent();

private:

std::string mEventId;

};
