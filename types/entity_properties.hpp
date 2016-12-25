
// ------------------------------------------------------------------------------
// Entities
// ------------------------------------------------------------------------------

struct EntityProperties
{
    std::string entityId;
    EntityOrientation defaultOrientation;
    int numLayers;
    SpriteLayer spriteLayers[256];
};

struct ObstacleProperties
{
    bool isDestructable;
};

struct HealthProperties
{
    bool isDestructable;
    int maxHealth;
    double healthRegenerationRate;
};

struct SurfaceProperties
{
    EntityProperties entityProperties;
    int weightValue;
};

struct BuildableObjectProperties
{
    EntityProperties entityProperties;
    HealthProperties healthProperties;
};
