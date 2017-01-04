class HandleBuildEvent : public IHandleEvent
{

public:

HandleBuildEvent(const std::string & eventId);
~HandleBuildEvent();

void handleEvent(IEventDispatch *eventManager);

private:

std::string mEventId;
std::string mEntityId;
};
