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

struct SpriteInfo
{
    int spriteId;
    std::string spriteSheetId;
};

enum EntityOrientation
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};
