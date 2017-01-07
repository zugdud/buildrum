class Timer
{

public:

Timer();
~Timer();

void start(const uint32_t & durationMs)
bool isDone();

private:

uint32_t mStartTime;
uint32_t mDuration;

};
