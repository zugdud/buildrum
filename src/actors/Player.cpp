#include "include/global.hpp"


Player::Player()
{
    configure();
}

Player::~Player()
{

}

void Player::configure()
{
    SDL_Log("Player::configure -- \n");
    // TODO config
    const std::string defaultBuildableObjectId = "banner_1";

    mSelectedBuildableActionProperties = ConfigManager::getInstance()->getBuildableObjectPropertiesImpl().getBuildableObjectProperties(defaultBuildableObjectId);
    mCredits = 100;
    mPlayerActionState = MOVE_ACTION;
    mCameraControll = true;
    // TODO Default selected item
}

const int & Player::getCredits()
{
    return mCredits;
}

void Player::setAction(const PlayerActionState & playerActionState)
{
    mPlayerActionState = playerActionState;
}

const PlayerActionState & Player::getAction()
{
    return mPlayerActionState;
}

const BuildableObjectProperties & Player::getSelectedBuildableObjectProperties()
{
    return mSelectedBuildableActionProperties;
}

void Player::setBuildableAction(const std::string & entityId)
{
    SDL_Log("Player::setBuildableAction -- entityId: %s \n", entityId.c_str());
    mSelectedBuildableActionProperties = ConfigManager::getInstance()->getBuildableObjectPropertiesImpl().getBuildableObjectProperties(entityId);
    mPlayerActionState = BUILD_ACTION;
}
