class HandleMainMenu : public IHandleEvent
{

public:

HandleMainMenu(const std::string & eventId);
~HandleMainMenu();

void handleEvent();

private:

std::string mEventId;

};
