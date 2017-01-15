class HandleToggleBuildMenu : public IHandleEvent
{

public:

HandleToggleBuildMenu(const std::string & eventId);
~HandleToggleBuildMenu();

void handleEvent(IEventDispatch *eventManager);

private:

std::string mEventId;
std::string mEntityId;
};
