#include "include/global.hpp"


void TimerManager::registerBuildTimerObserver(ITimerObserver *buildTimerObserver)
{
    mTimerObservers.push_back(buildTimerObserver);
}

void TimerManager::removeBuildTimerObserver(const std::string & id)
{
    for (size_t i = 0; i < mTimerObservers.size(); i++)
    {
        if (mTimerObservers[i]->getId() == id)
        {
            SDL_Log("TimerManager::removeBuildTimerObserver -- removing observer id: %s \n", id.c_str());
            mTimerObservers.erase(mTimerObservers.begin() + i);
        }
    }
}

void TimerManager::checkTimers()
{

}

};
