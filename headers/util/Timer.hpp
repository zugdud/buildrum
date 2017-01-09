class Timer
{

public:

Timer();
~Timer();

void start(const int & durationMs);

const bool & isRunning();
bool isDone();
double getTimerPercent();
void stop();

private:

bool mRunning;
uint32_t mStartTime;
int mDuration;

};
