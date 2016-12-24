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
    addInanimateObjectProperties("banner_1", "banner_1", 100);
    addInanimateObjectProperties("banner_2", "banner_2", 100);
    addInanimateObjectProperties("emblem_1", "emblem_1", 100);
    addInanimateObjectProperties("emblem_2", "emblem_2", 100);
    addInanimateObjectProperties("spire_1", "spire_1", 100);
    addInanimateObjectProperties("ladder_1", "ladder_1", 100);
    addInanimateObjectProperties("anvil_1", "anvil_1", 100);
    addInanimateObjectProperties("anvil_2", "anvil_2", 100);
    addInanimateObjectProperties("latern_1", "latern_1", 100);
    addInanimateObjectProperties("latern_1", "latern_1", 100);
    addInanimateObjectProperties("crate_1", "crate_1", 100);
    addInanimateObjectProperties("crate_2", "crate_2", 100);
    addInanimateObjectProperties("crate_3", "crate_3", 100);
    addInanimateObjectProperties("crate_4", "crate_4", 100);
    addInanimateObjectProperties("crate_5", "crate_5", 100);
    addInanimateObjectProperties("barrel_1", "barrel_1", 100);

    SDL_Log("InanimateObjectPropertiesImpl::loadInanmiateObjects -- loaded surface count: %zu \n", mInanimateObjectProperties.size());
}

void InanimateObjectPropertiesImpl::addInanimateObjectProperties(const std::string & entityId,
                                                                 const std::string & spriteName,
                                                                 const int & maxHealth)
{

    std::vector<SpriteProperties> spriteProperties;
    std::vector<std::string> spriteNames;
    spriteNames.push_back(spriteName);
    spriteNames.push_back(spriteName);
    spriteNames.push_back(spriteName);
    spriteNames.push_back(spriteName);

    std::vector<SpriteLayer> spriteLayers;
    spriteLayers.push_back(buildSpriteLayer(spriteNames));

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
        spriteLayer.spriteName_Up = spriteProperties[0];
        spriteLayer.spriteName_Down = spriteProperties[1];
        spriteLayer.spriteName_Left  = spriteProperties[2];
        spriteLayer.spriteName_Right = spriteProperties[3];
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
