class HandleMainMenu : public IHandleEvent
{

public:

HandleMainMenu(const std::string & eventId);
~HandleMainMenu();

void handleEvent(IEventDispatch *eventManager);

private:

std::string mEventId;

};
