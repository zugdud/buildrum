class TimerManager
{
public:

static TimerManager& Instance()
{
    static TimerManager instance;

    return instance;
}

void registerBuildTimerObserver(ITimerObserver *buildTimerObserver);
void removeBuildTimerObserver(const std::string & id);

void checkTimers();
void startBuildTimer(const int & tileId);

protected:

TimerManager();
TimerManager(const TimerManager&);
TimerManager& operator=(const TimerManager&);
~TimerManager();

private:

void notifyBuildTimerObservers();

Timer mBuildTimer;
int mBuildTileId;

int mBuildTimerDuration;

std::vector<ITimerObserver *> mBuildTimerObservers;


};
