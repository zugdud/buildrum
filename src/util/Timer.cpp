#include "include/global.hpp"

Timer::Timer()
{
    mStartTime = SDL_GetTicks();
    mDuration = 0;
}

Timer::~Timer()
{

}

void Timer::start(const uint32_t & durationMs)
{
    mStartTime = SDL_GetTicks();
    mDuration = durationMs;
}
bool Timer::isDone()
{
    const uint32_t currentTime = SDL_GetTicks();
    const int remaining =  currentTime - mStartTime;

    SDL_Log("Timer::isDone -- mStartTime: %zu currentTime: %zu mDuration: %zu remaining: %d \n",
            mStartTime,
            currentTime,
            mDuration,
            remaining);

    if (remaining > mDuration)
    {
        return true;
    }
    else
    {
        return false;
    }
}
