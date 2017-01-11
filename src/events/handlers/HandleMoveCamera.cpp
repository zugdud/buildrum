#include "include/global.hpp"

HandleMoveCamera::HandleMoveCamera(const std::string & eventId)
{
    mEventId = eventId;
}

HandleMoveCamera::~HandleMoveCamera()
{

}

void HandleMoveCamera::handleEvent(IEventDispatch *eventManager)
{
    Player::Instance().setAction(MOVE_ACTION);
}
