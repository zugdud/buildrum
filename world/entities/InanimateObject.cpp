#include "include/global.hpp"

InanimateObject::InanimateObject()
{
}

InanimateObject::~InanimateObject()
{

}

void InanimateObject::configure(const InanimateObjectProperties & surfaceProperties)
{

    mInanimateObjectProperties =  surfaceProperties;
    mEntityOrientation = surfaceProperties.entityProperties.defaultOrientation;

    setOrientation(mEntityOrientation);
}

const InanimateObjectProperties & InanimateObject::getInanimateObjectProperties() const
{
    return mInanimateObjectProperties;
}

void InanimateObject::setOrientation(const EntityOrientation & orientation)
{
    for (int i = 0; i < mInanimateObjectProperties.entityProperties.numLayers; i++)
    {
        switch (orientation)
        {
            case UP: mSpriteProperties.push_back(mInanimateObjectProperties.entityProperties.spriteLayers[i].spriteUp); break;
            case DOWN: mSpriteProperties.push_back(mInanimateObjectProperties.entityProperties.spriteLayers[i].spriteDown); break;
            case LEFT: mSpriteProperties.push_back(mInanimateObjectProperties.entityProperties.spriteLayers[i].spriteLeft); break;
            case RIGHT: mSpriteProperties.push_back(mInanimateObjectProperties.entityProperties.spriteLayers[i].spriteRight); break;
        }
    }
}
