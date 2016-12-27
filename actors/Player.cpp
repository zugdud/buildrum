#include "include/global.hpp"

Player::Player()
{
    mSelected = false;
    // TODO Default selected item
}

Player::~Player()
{

}

void Player::configure()
{
    SDL_Log("Player::configure -- \n");
}

const bool & Player::isSelected()
{
    return mSelected;
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
