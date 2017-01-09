class Timer
{

public:

Timer();
~Timer();

void start(const int & durationMs);

const bool & isRunning();
bool isDone();

private:

bool mRunning;
uint32_t mStartTime;
int mDuration;

};
