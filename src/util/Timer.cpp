#include "include/global.hpp"

Timer::Timer()
{
    mStartTime = SDL_GetTicks();
    mDuration = 0;
    mRunning = false;
}

Timer::~Timer()
{

}

void Timer::start(const int & durationMs)
{
    mStartTime = SDL_GetTicks();
    mDuration = durationMs;
    mRunning = true;
}

const bool & Timer::isRunning()
{
    return mRunning;
}

bool Timer::isDone()
{
    const uint32_t currentTime = SDL_GetTicks();
    const int remaining = currentTime - mStartTime;

    // SDL_Log("Timer::isDone -- mStartTime: %u currentTime: %u mDuration: %u remaining: %d \n",
    //         mStartTime,
    //         currentTime,
    //         mDuration,
    //         remaining);

    if (remaining > mDuration)
    {
        SDL_Log("Timer::isDone \n");
        mRunning = false;
        return true;
    }
    else
    {
        return false;
    }
}
