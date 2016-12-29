#include "include/global.hpp"

BuildableObjectPropertiesImpl::BuildableObjectPropertiesImpl()
{

}

BuildableObjectPropertiesImpl::~BuildableObjectPropertiesImpl()
{

}

void BuildableObjectPropertiesImpl::loadAll()
{
    SDL_Log("BuildableObjectPropertiesImpl::loadAll -- loading configuration ...\n");
    loadSurfaces();
}

void BuildableObjectPropertiesImpl::loadSurfaces()
{
    addBuildableObjectProperties("banner_1", "banner_1", 100, 10);
    addBuildableObjectProperties("banner_2", "banner_2", 100, 20);
    addBuildableObjectProperties("emblem_1", "emblem_1", 100, 30);
    addBuildableObjectProperties("emblem_2", "emblem_2", 100, 40);
    addBuildableObjectProperties("spire_1", "spire_1", 100, 50);
    addBuildableObjectProperties("ladder_1", "ladder_1", 100, 60);
    addBuildableObjectProperties("anvil_1", "anvil_1", 100, 70);
    addBuildableObjectProperties("anvil_2", "anvil_2", 100, 80);
    addBuildableObjectProperties("latern_1", "latern_1", 100, 90);
    addBuildableObjectProperties("latern_1", "latern_1", 100, 100);
    addBuildableObjectProperties("crate_1", "crate_1", 100, 110);
    addBuildableObjectProperties("crate_2", "crate_2", 100, 120);
    addBuildableObjectProperties("crate_3", "crate_3", 100, 130);
    addBuildableObjectProperties("crate_4", "crate_4", 100, 140);
    addBuildableObjectProperties("crate_5", "crate_5", 100, 150);
    addBuildableObjectProperties("barrel_1", "barrel_1", 100, 160);

    SDL_Log("BuildableObjectPropertiesImpl::loadInanmiateObjects -- loaded surface count: %zu \n", mBuildableObjectProperties.size());
}

void BuildableObjectPropertiesImpl::addBuildableObjectProperties(const std::string & entityId,
                                                                 const std::string & spriteName,
                                                                 const int & maxHealth,
                                                                 const int & creditCost)
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
    CombatProperties combatProperties = buildCombatProperties(false, 2, 10, 10);
    HealthProperties healthProperties = buildHealthProperties(isDestructable, maxHealth, healthRegenerationRate);
    BuildableObjectProperties buildableObjectProperties = buildBuildableObject(entityProperties,
                                                                               healthProperties,
                                                                               combatProperties,
                                                                               creditCost);

    mBuildableObjectProperties[entityId] = buildableObjectProperties;
}

SpriteLayer BuildableObjectPropertiesImpl::buildSpriteLayer(const std::vector<std::string> & spriteProperties)
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
        SDL_Log("BuildableObjectPropertiesImpl::buildSpriteLayer -- ERROR: spriteProperties.size() out of bounds: %zu \n", spriteProperties.size());
    }

    SDL_Log("BuildableObjectPropertiesImpl::buildSpriteLayer -- spriteLayer size:  %zu \n", spriteProperties.size());
    return spriteLayer;
}


EntityProperties BuildableObjectPropertiesImpl::buildEntity(const std::string & entityId,
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

CombatProperties BuildableObjectPropertiesImpl::buildCombatProperties(const bool & isAttacker,
                                                                      const int & range,
                                                                      const int & damage,
                                                                      const int & apCost)
{
    CombatProperties combatProperties;

    combatProperties.isAttacker = isAttacker;
    combatProperties.range = range;
    combatProperties.damage = damage;
    combatProperties.apCost = apCost;

    return combatProperties;
}

HealthProperties BuildableObjectPropertiesImpl::buildHealthProperties(const bool & isDestructable,
                                                                      const int & maxHealth,
                                                                      double & healthRegenerationRate)
{

    HealthProperties healthProperties;

    healthProperties.isDestructable = isDestructable;
    healthProperties.maxHealth = maxHealth;
    healthProperties.healthRegenerationRate = healthRegenerationRate;

    return healthProperties;
}

BuildableObjectProperties BuildableObjectPropertiesImpl::buildBuildableObject(const EntityProperties & entityProperties,
                                                                              const HealthProperties & healthProperties,
                                                                              const CombatProperties & combatProperties,
                                                                              const int & creditCost)
{
    BuildableObjectProperties buildableObjectProperties;

    buildableObjectProperties.entityProperties = entityProperties;
    buildableObjectProperties.healthProperties = healthProperties;
    buildableObjectProperties.combatProperties = combatProperties;
    buildableObjectProperties.creditCost = creditCost;
    return buildableObjectProperties;
}

const BuildableObjectProperties & BuildableObjectPropertiesImpl::getBuildableObjectProperties(const std::string & entityId) const
{
    return mBuildableObjectProperties.find(entityId)->second;
}
