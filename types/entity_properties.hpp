
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

struct SurfaceProperties
{
    EntityProperties entityProperties;
    int weightValue;
};
