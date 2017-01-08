#include "include/global.hpp"

TimerManager::TimerManager()
{
    mBuildTileId = 0;
    mBuildTimerDuration = 5000;
}
TimerManager::~TimerManager()
{

}

void TimerManager::registerBuildTimerObserver(ITimerObserver *buildTimerObserver)
{
    mBuildTimerObservers.push_back(buildTimerObserver);
}

void TimerManager::removeBuildTimerObserver(const std::string & id)
{
    for (size_t i = 0; i < mBuildTimerObservers.size(); i++)
    {
        if (mBuildTimerObservers[i]->getId() == id)
        {
            SDL_Log("TimerManager::removeBuildTimerObserver -- removing observer id: %s \n", id.c_str());
            mBuildTimerObservers.erase(mBuildTimerObservers.begin() + i);
        }
    }
}

void TimerManager::notifyBuildTimerObservers()
{
    for (size_t i = 0; i < mBuildTimerObservers.size(); i++)
    {
        SDL_Log("TimerManager::notifyBuildTimerObservers -- timer complete, id: %s \n", mBuildTimerObservers[i]->getId().c_str());
        mBuildTimerObservers[i]->buildTimerComplete(mBuildTileId);
    }
}

void TimerManager::startBuildTimer(const int & tileId)
{
    mBuildTileId = tileId;
    SDL_Log("TimerManager::startBuildTimer -- mBuildTileId: %d \n", mBuildTileId);
    mBuildTimer.start(mBuildTimerDuration);
}

void TimerManager::checkTimers()
{
    if (mBuildTimer.isRunning())
    {
        if (mBuildTimer.isDone())
        {
            notifyBuildTimerObservers();
        }
    }
}
