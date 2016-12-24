class EventManager : public UIEventConnector
{

static EventManager *mSingletonInstance;

public:

static EventManager * getInstance();
void configure(AudioManager *audioManager);
void uiEventRaised(const std::string & eventId);

void registerObserver(IEventObserver *eventObserver);
void removeObserver(const std::string & id);

protected:

EventManager();
EventManager(const EventManager *);
EventManager& operator=(const EventManager *);
~EventManager();

private:

std::map<std::string, IHandleEvent *> mEventHandlers;

void dispatchEvent(const std::string & eventId);
std::vector<IEventObserver *> mEventObservers;

AudioManager *mAudioManager;

};
