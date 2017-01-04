#include "include/global.hpp"

BuildableObject::BuildableObject()
{
}

BuildableObject::~BuildableObject()
{

}

void BuildableObject::configure(const BuildableObjectProperties & surfaceProperties)
{

    mBuildableObjectProperties =  surfaceProperties;
    mEntityOrientation = surfaceProperties.entityProperties.defaultOrientation;

    setOrientation(mEntityOrientation);
}

const BuildableObjectProperties & BuildableObject::getBuildableObjectProperties() const
{
    return mBuildableObjectProperties;
}

void BuildableObject::setOrientation(const EntityOrientation & orientation)
{
    mSpriteProperties.clear();

    for (int i = 0; i < mBuildableObjectProperties.entityProperties.numLayers; i++)
    {
        std::string spriteName;
        switch (orientation)
        {
            case UP: spriteName = mBuildableObjectProperties.entityProperties.spriteLayers[i].spriteName_Up; break;
            case DOWN: spriteName = mBuildableObjectProperties.entityProperties.spriteLayers[i].spriteName_Down; break;
            case LEFT: spriteName = mBuildableObjectProperties.entityProperties.spriteLayers[i].spriteName_Left; break;
            case RIGHT: spriteName = mBuildableObjectProperties.entityProperties.spriteLayers[i].spriteName_Right; break;
        }
        const SpriteProperties & spriteProperties = ConfigManager::getInstance()->getSpritePropertiesImpl().getSpriteProperties(spriteName);
        mSpriteProperties.push_back(spriteProperties);
    }
}
