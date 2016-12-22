struct PointInt
{
    int x;
    int y;
};

struct PointDouble
{
    double x;
    double y;
};

enum EntityOrientation
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

struct TextLabel
{
    SDL_Texture *labelTexture;
    SDL_Rect rect;
};

struct SelectedPoint
{
    SDL_Point viewportOffset;
    std::string viewportId;
};

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
