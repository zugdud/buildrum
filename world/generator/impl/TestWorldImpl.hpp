class TestWorldImpl
{
public:

TestWorldImpl();
~TestWorldImpl();

void setWorld(World & world);

private:

void setTile(Tile & tile);
void setSurface(Surface & surface);

int mTileCount;
SurfacePropertiesImpl mSurfacePropertiesImpl;
std::vector<Tile> mTiles;

};
