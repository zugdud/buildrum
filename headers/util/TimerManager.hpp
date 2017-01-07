class TimerManager
{
public:

static TimerManager& Instance()
{
    static TimerManager instance;

    return instance;
}

void registerBuildTimerObserver(ITimerObserver *buildTimerObserver);
void checkTimers();

protected:

TimerManager();
TimerManager(const TimerManager&);
TimerManager& operator=(const TimerManager&);
~TimerManager();

private:

Timer mBuildTimer;
std::vector<ITimerObserver *> mTimerObservers;


};
