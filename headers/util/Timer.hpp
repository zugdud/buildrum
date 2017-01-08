class Timer
{

public:

Timer();
~Timer();

void start(const uint32_t & durationMs);

const bool & isRunning();
bool isDone();

private:

bool mRunning;
uint32_t mStartTime;
uint32_t mDuration;

};
