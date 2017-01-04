#include "include/global.hpp"

Surface::Surface()
{
}

Surface::~Surface()
{

}

void Surface::configure(const SurfaceProperties & surfaceProperties)
{

    mSurfaceProperties =  surfaceProperties;
    mEntityOrientation = surfaceProperties.entityProperties.defaultOrientation;

    setOrientation(mEntityOrientation);
}

const SurfaceProperties & Surface::getSurfaceProperties() const
{
    return mSurfaceProperties;
}

void Surface::setOrientation(const EntityOrientation & orientation)
{
    mSpriteProperties.clear();

    for (int i = 0; i < mSurfaceProperties.entityProperties.numLayers; i++)
    {
        std::string spriteName;
        switch (orientation)
        {
            case UP: spriteName = mSurfaceProperties.entityProperties.spriteLayers[i].spriteName_Up; break;
            case DOWN: spriteName = mSurfaceProperties.entityProperties.spriteLayers[i].spriteName_Down; break;
            case LEFT: spriteName = mSurfaceProperties.entityProperties.spriteLayers[i].spriteName_Left; break;
            case RIGHT: spriteName = mSurfaceProperties.entityProperties.spriteLayers[i].spriteName_Right; break;
        }
        const SpriteProperties & spriteProperties = ConfigManager::getInstance()->getSpritePropertiesImpl().getSpriteProperties(spriteName);
        mSpriteProperties.push_back(spriteProperties);
    }
}
