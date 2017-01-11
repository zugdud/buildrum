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
    mSelected = false;
    mCameraControll = true;
    // TODO Default selected item
}

const int & Player::getCredits()
{
    return mCredits;
}

const BuildableObjectProperties & Player::getSelectedBuildableObjectProperties()
{
    return mSelectedBuildableActionProperties;
}

void Player::setBuildableAction(const std::string & entityId)
{
    SDL_Log("Player::setBuildableAction -- entityId: %s \n", entityId.c_str());
    mSelectedBuildableActionProperties = ConfigManager::getInstance()->getBuildableObjectPropertiesImpl().getBuildableObjectProperties(entityId);
    mSelected = true;
}
