#include "include/global.hpp"

Entity::Entity()
{
}

Entity::~Entity()
{

}



const EntityOrientation & Entity::getEntityOrientation() const
{
    return mEntityOrientation;
}

const std::vector<SpriteProperties> & Entity::getSpriteProperties() const
{
    return mSpriteProperties;
}
