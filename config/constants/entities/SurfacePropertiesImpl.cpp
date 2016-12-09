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

void SurfacePropertiesImpl::loadSurface(const std::string & entityId,
                                        const)
{

    std::vector<SpriteProperties> spriteProperties;
    spriteProperties.push_back(buildSpriteProperties(200, "castle_1"));
    spriteProperties.push_back(buildSpriteProperties(200, "castle_1"));
    spriteProperties.push_back(buildSpriteProperties(200, "castle_1"));
    spriteProperties.push_back(buildSpriteProperties(200, "castle_1"));

    std::vector<SpriteLayer> spriteLayers;
    spriteLayers.push_back(buildSpriteLayer(spriteProperties));
    mSurfaceProperties["field_1"] = buildSurface(buildEntity("field_1", spriteLayers), 10);

}

SpriteProperties SurfacePropertiesImpl::buildSpriteProperties(const int & spriteId,
                                                              const std::string spriteSheetId)
{
    SpriteProperties spriteProperties = { spriteId, spriteSheetId, SDL_FLIP_NONE, 0 };

    return spriteProperties;
}

SpriteLayer SurfacePropertiesImpl::buildSpriteLayer(const std::vector<SpriteProperties> & spriteProperties)
{
    if (spriteProperties.size() == 4)
    {
        SpriteProperties up = spriteProperties[0];
        SpriteProperties down = spriteProperties[1];
        SpriteProperties left = spriteProperties[2];
        SpriteProperties right = spriteProperties[3];

        SpriteLayer spriteLayer;
        spriteLayer.spriteUp = up;
        spriteLayer.spriteDown = down;
        spriteLayer.spriteLeft = left;
        spriteLayer.spriteRight = right;
        return spriteLayer;
    }
    else
    {
        SDL_Log("SurfacePropertiesImpl::buildSpriteLayer -- ERROR: spriteProperties.size() out of bounds: %zu \n", spriteProperties.size());
    }
}

EntityProperties SurfacePropertiesImpl::buildEntity(const std::string & entityId,
                                                    const std::vector<SpriteLayer> & spriteLayers)
{
    EntityProperties entityProperties;

    entityProperties.entityId = entityId;
    entityProperties.defaultOrientation = UP;
    entityProperties.numLayers = spriteLayers.size();
    int numLayers;
    for (size_t i = 0; i < spriteLayers.size(); i++)
    {
        entityProperties.spriteLayers[i] = spriteLayers[i];
    }
}

EntityProperties SurfacePropertiesImpl::buildSurface(const EntityProperties & entityProperties,
                                                     const int & weight)
{

}

const SurfaceProperties &  SurfacePropertiesImpl::getSurfaceProperties(const std::string entityId)
{
    return mSurfaceProperties[entityId];
}
