#include "include/global.hpp"

TimerManager::TimerManager()
{
    mBuildTileId = 0;
    mBuildTimerDuration = 2000;
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

void TimerManager::stopBuildTimer()
{
    mBuildTimer.stop();
}

void TimerManager::startBuildTimer(const int & tileId)
{
    AudioManager::Instance().playSound("building_1");
    mBuildTileId = tileId;
    SDL_Log("TimerManager::startBuildTimer -- mBuildTileId: %d \n", mBuildTileId);
    mBuildTimer.start(mBuildTimerDuration);
}

double TimerManager::getBuildTimerPercent()
{
    return mBuildTimer.getTimerPercent();
}

const bool & TimerManager::isBuilding()
{
    return mBuildTimer.isRunning();
}

void TimerManager::checkTimers()
{
    if (mBuildTimer.isRunning())
    {
        if (mBuildTimer.isDone())
        {
            AudioManager::Instance().playSound("build_complete_1");
            notifyBuildTimerObservers();
        }
    }
}
