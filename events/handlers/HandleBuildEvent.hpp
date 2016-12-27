class HandleBuildEvent : public IHandleEvent
{

public:

HandleBuildEvent(const std::string & eventId);
~HandleBuildEvent();

void handleEvent();

private:

std::string mEventId;
std::string mEntityId;
};
