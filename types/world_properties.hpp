// ------------------------------------------------------------------------------
// World
// ------------------------------------------------------------------------------

struct WorldProperties
{
    std::string worldId;
    int rows;
    int columns;
    int numTiles;
    int textureSize;
};

struct TileProperties
{
    int tileId;
    bool drawBorder;
    SDL_Color borderColor;
    bool fillBackground;
    SDL_Color backgroundColor;
    bool showTileIdText;
    std::string fontProfileName;
};
