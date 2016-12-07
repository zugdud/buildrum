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

struct SpriteProperties
{
    int spriteId;
    std::string spriteSheetId;
    SDL_RendererFlip sdlRendererFlip;
    double angle;
};

enum EntityOrientation
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};
