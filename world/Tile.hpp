class Tile
{
public:

Tile(const int & tileId);
~Tile();

void setSurface

private:

int tileId;
std::vector<Surface> mSurfaces;

};
