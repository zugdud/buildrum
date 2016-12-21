#include "include/global.hpp"

PlayerPaletteImpl::PlayerPaletteImpl()
{

}

PlayerPaletteImpl::~PlayerPaletteImpl()
{

}

void PlayerPaletteImpl::loadAll()
{
    SDL_Log("PlayerPaletteImpl::loadAll -- loading configuration ...\n");
    loadSurfaces();
}

void PlayerPaletteImpl::loadSurfaces()
{
    addSurface("banner_1", 96, "castle_2", 100);
    addSurface("banner_2", 112, "castle_2", 100);

    addSurface("emblem_1", 99, "castle_2", 100);
    addSurface("emblem_2", 115, "castle_2", 100);

    addSurface("spire_1", 128, "castle_2", 100);

    addSurface("ladder_1", 146, "castle_2", 100);

    addSurface("anvil_1", 133, "castle_1", 100);
    addSurface("anvil_2", 149, "castle_1", 100);

    addSurface("latern_1", 100, "castle_1", 100);
    addSurface("latern_1", 116, "castle_1", 100);

    addSurface("crate_1", 129, "castle_1", 100);
    addSurface("crate_2", 131, "castle_1", 100);
    addSurface("crate_3", 134, "castle_1", 100);
    addSurface("crate_4", 150, "castle_1", 100);
    addSurface("crate_5", 234, "castle_1", 100);

    addSurface("barrel_1", 233, "castle_1", 100);

    SDL_Log("PlayerPaletteImpl::loadInanmiateObjects -- loaded surface count: %zu \n", mSurfaceProperties.size());
}

void PlayerPaletteImpl::addInanimateObjectProperties(const std::string & entityId,
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

    SurfaceProperties surfaceProperties = buildInanimateObject(entityProperties, );

    mSurfaceProperties[entityId] = surfaceProperties;
}

SpriteProperties PlayerPaletteImpl::buildSpriteProperties(const int & spriteId,
                                                          const std::string spriteSheetId)
{
    SpriteProperties spriteProperties = { spriteId, spriteSheetId, SDL_FLIP_NONE, 0 };

    return spriteProperties;
}

SpriteLayer PlayerPaletteImpl::buildSpriteLayer(const std::vector<SpriteProperties> & spriteProperties)
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
        SDL_Log("PlayerPaletteImpl::buildSpriteLayer -- ERROR: spriteProperties.size() out of bounds: %zu \n", spriteProperties.size());
    }

    SDL_Log("PlayerPaletteImpl::buildSpriteLayer -- spriteLayer size:  %zu \n", spriteProperties.size());
    return spriteLayer;
}

EntityProperties PlayerPaletteImpl::buildEntity(const bool & isDestructable,
                                                const int & maxHealth,
                                                double & healthRegenerationRate)
{



}

EntityProperties PlayerPaletteImpl::buildEntity(const std::string & entityId,
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

InanimateObjectProperties PlayerPaletteImpl::buildInanimateObject(const EntityProperties & entityProperties,
                                                                  const HealthProperties & healthProperties);
{
    InanimateObjectProperties inanimateObjectProperties;

    inanimateObjectProperties.entityProperties = entityProperties;
    inanimateObjectProperties.healthProperties = healthProperties;

    return inanimateObjectProperties;
}

const InanimateObjectProperties &  PlayerPaletteImpl::getInanimateObjectProperties(const std::string entityId)
{
    return mSurfaceProperties[entityId];
}
