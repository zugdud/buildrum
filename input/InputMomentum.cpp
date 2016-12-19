#include "include/global.hpp"

// TODO config
InputMomentum::InputMomentum()
{
    mDecayRate.x = 0.99;
    mDecayRate.y = 0.99;
    mDecayCounterLimit = 30;
    SDL_Log("InputMomentum::InputMomentum -- mDecayCounterLimit: %d DecayRate: [x: %f y: %f] \n", mDecayCounterLimit, mDecayRate.x, mDecayRate.y);

    mDecayCounter = 0;
}

InputMomentum::~InputMomentum()
{

}

void InputMomentum::update(const int & x, const int & y)
{
    mMomentum.x = x;
    mMomentum.y = y;
    mDecayCounter = 0;
    // SDL_Log("InputMomentum::updateMomentum -- mMomentum: [x: %d y: %d] \n", mMomentum.x, mMomentum.y);
}

const PointInt & InputMomentum::decay()
{
    if (mDecayCounter < mDecayCounterLimit)
    {
        mMomentum.x = mMomentum.x * mDecayRate.x;
        mMomentum.y = mMomentum.y * mDecayRate.y;
        mDecayCounter++;
    }
    else
    {
        mMomentum.x = 0;
        mMomentum.y = 0;
    }
    // SDL_Log("InputMomentum::decayMomentum -- mDecayCounter: %d mMomentum: [x: %d y: %d] \n", mDecayCounter, mMomentum.x, mMomentum.y);
    return mMomentum;
}
