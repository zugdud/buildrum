#include "include/global.hpp"

SurfacePropertiesImpl::SurfacePropertiesImpl()
{

}

SurfacePropertiesImpl::~SurfacePropertiesImpl()
{

}

void SurfacePropertiesImpl::loadAll()
{
    SDL_Log("SurfacePropertiesImpl::loadAll -- loading configuration ...\n");
    loadSurfaces();
}

void SurfacePropertiesImpl::loadSurfaces()
{
    addSurface("brick_1", "brick_1", 10);
    addSurface("brick_2", "brick_2", 10);

    addSurface("field_1", "field_1", 10);
    addSurface("field_2", "field_2", 10);
    addSurface("field_3", "field_3", 10);
    addSurface("water_1", "water_1", 100);

    SDL_Log("SurfacePropertiesImpl::loadSurfaces -- loaded surface count: %zu \n", mSurfaceProperties.size());
}

void SurfacePropertiesImpl::addSurface(const std::string & entityId,
                                       const std::string & spriteName,
                                       const int & weightValue)
{

    std::vector<std::string> spriteNames;
    spriteNames.push_back(spriteName);
    spriteNames.push_back(spriteName);
    spriteNames.push_back(spriteName);
    spriteNames.push_back(spriteName);

    std::vector<SpriteLayer> spriteLayers;
    spriteLayers.push_back(buildSpriteLayer(spriteNames));
    EntityProperties entityProperties = buildEntity(entityId, spriteLayers);
    SurfaceProperties surfaceProperties = buildSurface(entityProperties, weightValue);
    mSurfaceProperties[entityId] = surfaceProperties;
}

SpriteLayer SurfacePropertiesImpl::buildSpriteLayer(const std::vector<std::string> & spriteProperties)
{
    SpriteLayer spriteLayer;

    if (spriteProperties.size() == 4)
    {
        spriteLayer.spriteName_Up = spriteProperties[0];
        spriteLayer.spriteName_Down = spriteProperties[1];
        spriteLayer.spriteName_Left  = spriteProperties[2];
        spriteLayer.spriteName_Right = spriteProperties[3];
    }
    else
    {
        SDL_Log("SurfacePropertiesImpl::buildSpriteLayer -- ERROR: spriteProperties.size() out of bounds: %zu \n", spriteProperties.size());
    }

    SDL_Log("SurfacePropertiesImpl::buildSpriteLayer -- spriteLayer size:  %zu \n", spriteProperties.size());
    return spriteLayer;
}

EntityProperties SurfacePropertiesImpl::buildEntity(const std::string & entityId,
                                                    const std::vector<SpriteLayer> & spriteLayers)
{
    EntityProperties entityProperties;

    entityProperties.entityId = entityId;
    entityProperties.defaultOrientation = UP;
    entityProperties.numLayers = spriteLayers.size();
    for (size_t i = 0; i < spriteLayers.size(); i++)
    {
        entityProperties.spriteLayers[i] = spriteLayers[i];
    }
    return entityProperties;
}

SurfaceProperties SurfacePropertiesImpl::buildSurface(const EntityProperties & entityProperties,
                                                      const int & weight)
{
    SurfaceProperties surfaceProperties;

    surfaceProperties.entityProperties = entityProperties;
    surfaceProperties.weightValue = weight;

    return surfaceProperties;
}

const SurfaceProperties &  SurfacePropertiesImpl::getSurfaceProperties(const std::string & entityId) const
{
    return mSurfaceProperties.at(entityId);
}
