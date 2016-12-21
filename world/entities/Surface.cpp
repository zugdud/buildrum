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
    for (int i = 0; i < mSurfaceProperties.entityProperties.numLayers; i++)
    {
        switch (orientation)
        {
            case UP: mSpriteProperties.push_back(mSurfaceProperties.entityProperties.spriteLayers[i].spriteUp); break;
            case DOWN: mSpriteProperties.push_back(mSurfaceProperties.entityProperties.spriteLayers[i].spriteDown); break;
            case LEFT: mSpriteProperties.push_back(mSurfaceProperties.entityProperties.spriteLayers[i].spriteLeft); break;
            case RIGHT: mSpriteProperties.push_back(mSurfaceProperties.entityProperties.spriteLayers[i].spriteRight); break;
        }
    }
}
