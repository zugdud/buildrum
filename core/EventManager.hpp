class EventManager : public UIEventConnector
{

static EventManager *mSingletonInstance;

public:

static EventManager * getInstance();
void configure(AudioManager *audioManager);
void uiEventRaised(const std::string & eventId);

protected:

EventManager();
EventManager(const EventManager *);
EventManager& operator=(const EventManager *);
~EventManager();

private:

AudioManager *mAudioManager;

};
