#include "include/global.hpp"

InanimateObject::InanimateObject()
{
}

InanimateObject::~InanimateObject()
{

}

void InanimateObject::configure(const BuildableObjectProperties & surfaceProperties)
{

    mBuildableObjectProperties =  surfaceProperties;
    mEntityOrientation = surfaceProperties.entityProperties.defaultOrientation;

    setOrientation(mEntityOrientation);
}

const BuildableObjectProperties & InanimateObject::getBuildableObjectProperties() const
{
    return mBuildableObjectProperties;
}

void InanimateObject::setOrientation(const EntityOrientation & orientation)
{
    for (int i = 0; i < mBuildableObjectProperties.entityProperties.numLayers; i++)
    {
        switch (orientation)
        {
            case UP: mSpriteProperties.push_back(mBuildableObjectProperties.entityProperties.spriteLayers[i].spriteUp); break;
            case DOWN: mSpriteProperties.push_back(mBuildableObjectProperties.entityProperties.spriteLayers[i].spriteDown); break;
            case LEFT: mSpriteProperties.push_back(mBuildableObjectProperties.entityProperties.spriteLayers[i].spriteLeft); break;
            case RIGHT: mSpriteProperties.push_back(mBuildableObjectProperties.entityProperties.spriteLayers[i].spriteRight); break;
        }
    }
}
