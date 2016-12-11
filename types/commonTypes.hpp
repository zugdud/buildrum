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
