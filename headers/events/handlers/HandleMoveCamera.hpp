class HandleMoveCamera : public IHandleEvent
{

public:

HandleMoveCamera(const std::string & eventId);
~HandleMoveCamera();

void handleEvent(IEventDispatch *eventManager);

private:

std::string mEventId;

};
