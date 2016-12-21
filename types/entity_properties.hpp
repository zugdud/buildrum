
// ------------------------------------------------------------------------------
// Entities
// ------------------------------------------------------------------------------

struct SpriteProperties
{
    int spriteId;
    std::string spriteSheetId;
    SDL_RendererFlip sdlRendererFlip;
    double angle;
};

struct SpriteLayer
{
    SpriteProperties spriteUp;
    SpriteProperties spriteDown;
    SpriteProperties spriteLeft;
    SpriteProperties spriteRight;
};

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

struct InanimateObjectProperties
{
    EntityProperties entityProperties;
    HealthProperties healthProperties;
};
