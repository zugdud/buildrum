class ITimerObserver
{

public:

virtual void buildTimerComplete(const int & tileId) = 0;
virtual const std::string & getId() = 0;

};
