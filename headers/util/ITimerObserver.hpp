class ITimerObserver
{

public:

virtual void timerComplete() = 0;
virtual const std::string & getId() = 0;

};
