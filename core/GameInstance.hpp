class GameInstance : public QuitEventObserver, public IEventObserver
{
public:

GameInstance();
~GameInstance();

bool init();
void run();

virtual void eventRaised(const std::string & eventId);
virtual const std::string & getId();

private:

void quitEventCallback();

bool mRunning;
std::string mObserverId;

};
