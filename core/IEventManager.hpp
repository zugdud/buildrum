class IEventObserver
{
public:

virtual void eventRaised(const std::string & eventId) = 0;
virtual const std::string & getId() = 0;

};

class UIEventConnector
{

public:

virtual void uiEventRaised(const std::string & eventId) = 0;

};
