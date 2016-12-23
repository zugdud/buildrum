#include "include/global.hpp"

InanimateObjectPropertiesImpl::InanimateObjectPropertiesImpl()
{

}

InanimateObjectPropertiesImpl::~InanimateObjectPropertiesImpl()
{

}

void InanimateObjectPropertiesImpl::loadAll()
{
    SDL_Log("InanimateObjectPropertiesImpl::loadAll -- loading configuration ...\n");
    loadSurfaces();
}

void InanimateObjectPropertiesImpl::loadSurfaces()
{
    addInanimateObjectProperties("banner_1", 96, "castle_2", 100);
    addInanimateObjectProperties("banner_2", 112, "castle_2", 100);

    addInanimateObjectProperties("emblem_1", 99, "castle_2", 100);
    addInanimateObjectProperties("emblem_2", 115, "castle_2", 100);

    addInanimateObjectProperties("spire_1", 128, "castle_2", 100);

    addInanimateObjectProperties("ladder_1", 146, "castle_2", 100);

    addInanimateObjectProperties("anvil_1", 133, "castle_1", 100);
    addInanimateObjectProperties("anvil_2", 149, "castle_1", 100);

    addInanimateObjectProperties("latern_1", 100, "castle_1", 100);
    addInanimateObjectProperties("latern_1", 116, "castle_1", 100);

    addInanimateObjectProperties("crate_1", 129, "castle_1", 100);
    addInanimateObjectProperties("crate_2", 131, "castle_1", 100);
    addInanimateObjectProperties("crate_3", 134, "castle_1", 100);
    addInanimateObjectProperties("crate_4", 150, "castle_1", 100);
    addInanimateObjectProperties("crate_5", 234, "castle_1", 100);

    addInanimateObjectProperties("barrel_1", 233, "castle_1", 100);

    SDL_Log("InanimateObjectPropertiesImpl::loadInanmiateObjects -- loaded surface count: %zu \n", mInanimateObjectProperties.size());
}

void InanimateObjectPropertiesImpl::addInanimateObjectProperties(const std::string & entityId,
                                                                 const std::string & spriteName,
                                                                 const int & maxHealth)
{

    std::vector<SpriteProperties> spriteProperties;
    std::vector<std::string> spriteNames;
    spriteProperties.push_back(spriteName);
    spriteProperties.push_back(spriteName);
    spriteProperties.push_back(spriteName);
    spriteProperties.push_back(spriteName);

    std::vector<SpriteLayer> spriteLayers;
    spriteLayers.push_back(buildSpriteLayer(spriteProperties));

    EntityProperties entityProperties = buildEntity(entityId, spriteLayers);

    bool isDestructable = true;
    double healthRegenerationRate = 0.0;
    HealthProperties healthProperties = buildHealthProperties(isDestructable, maxHealth, healthRegenerationRate);
    InanimateObjectProperties inanimateObjectProperties = buildInanimateObject(entityProperties, healthProperties);

    mInanimateObjectProperties[entityId] = inanimateObjectProperties;
}

SpriteLayer InanimateObjectPropertiesImpl::buildSpriteLayer(const std::vector<std::string> & spriteProperties)
{
    SpriteLayer spriteLayer;

    if (spriteProperties.size() == 4)
    {
        SpriteProperties up = spriteProperties[0];
        SpriteProperties down = spriteProperties[1];
        SpriteProperties left = spriteProperties[2];
        SpriteProperties right = spriteProperties[3];

        spriteLayer.spriteName_Up = up;
        spriteLayer.spriteName_Down = down;
        spriteLayer.spriteName_Left = left;
        spriteLayer.spriteName_Right = right;

    }
    else
    {
        SDL_Log("InanimateObjectPropertiesImpl::buildSpriteLayer -- ERROR: spriteProperties.size() out of bounds: %zu \n", spriteProperties.size());
    }

    SDL_Log("InanimateObjectPropertiesImpl::buildSpriteLayer -- spriteLayer size:  %zu \n", spriteProperties.size());
    return spriteLayer;
}


EntityProperties InanimateObjectPropertiesImpl::buildEntity(const std::string & entityId,
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

HealthProperties InanimateObjectPropertiesImpl::buildHealthProperties(const bool & isDestructable,
                                                                      const int & maxHealth,
                                                                      double & healthRegenerationRate)
{

    HealthProperties healthProperties;

    healthProperties.isDestructable = isDestructable;
    healthProperties.maxHealth = maxHealth;
    healthProperties.healthRegenerationRate = healthRegenerationRate;

    return healthProperties;
}

InanimateObjectProperties InanimateObjectPropertiesImpl::buildInanimateObject(const EntityProperties & entityProperties,
                                                                              const HealthProperties & healthProperties)
{
    InanimateObjectProperties inanimateObjectProperties;

    inanimateObjectProperties.entityProperties = entityProperties;
    inanimateObjectProperties.healthProperties = healthProperties;

    return inanimateObjectProperties;
}

const InanimateObjectProperties & InanimateObjectPropertiesImpl::getInanimateObjectProperties(const std::string entityId)
{
    return mInanimateObjectProperties[entityId];
}
