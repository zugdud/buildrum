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
    addSurface("brick_1", 24, "castle_1", 10);
    addSurface("brick_2", 65, "castle_1", 10);

    addSurface("field_1", 195, "castle_1", 10);
    addSurface("field_2", 196, "castle_1", 10);
    addSurface("field_3", 213, "castle_1", 10);
    addSurface("water_1", 192, "castle_2", 100);

    SDL_Log("SurfacePropertiesImpl::loadSurfaces -- loaded surface count: %zu \n", mSurfaceProperties.size());
}

void SurfacePropertiesImpl::addSurface(const std::string & entityId,
                                       const int & spriteId,
                                       const std::string & spriteSheetId,
                                       const int & weightValue)
{

    std::vector<SpriteProperties> spriteProperties;
    spriteProperties.push_back(buildSpriteProperties(spriteId, spriteSheetId));
    spriteProperties.push_back(buildSpriteProperties(spriteId, spriteSheetId));
    spriteProperties.push_back(buildSpriteProperties(spriteId, spriteSheetId));
    spriteProperties.push_back(buildSpriteProperties(spriteId, spriteSheetId));

    std::vector<SpriteLayer> spriteLayers;
    spriteLayers.push_back(buildSpriteLayer(spriteProperties));
    EntityProperties entityProperties = buildEntity(entityId, spriteLayers);
    SurfaceProperties surfaceProperties = buildSurface(entityProperties, weightValue);
    mSurfaceProperties[entityId] = surfaceProperties;
}

SpriteProperties SurfacePropertiesImpl::buildSpriteProperties(const int & spriteId,
                                                              const std::string spriteSheetId)
{
    SpriteProperties spriteProperties = { spriteId, spriteSheetId, SDL_FLIP_NONE, 0 };

    return spriteProperties;
}

SpriteLayer SurfacePropertiesImpl::buildSpriteLayer(const std::vector<SpriteProperties> & spriteProperties)
{
    SpriteLayer spriteLayer;

    if (spriteProperties.size() == 4)
    {
        SpriteProperties up = spriteProperties[0];
        SpriteProperties down = spriteProperties[1];
        SpriteProperties left = spriteProperties[2];
        SpriteProperties right = spriteProperties[3];

        spriteLayer.spriteUp = up;
        spriteLayer.spriteDown = down;
        spriteLayer.spriteLeft = left;
        spriteLayer.spriteRight = right;

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

const SurfaceProperties &  SurfacePropertiesImpl::getSurfaceProperties(const std::string entityId)
{
    return mSurfaceProperties[entityId];
}
