class TestWorldImpl
{
public:

TestWorldImpl();
~TestWorldImpl();

void setWorld(World & world);

private:

void setWorldProperties();

Tile createTile(const int & tileId);
Surface createSurface();

SurfacePropertiesImpl mSurfacePropertiesImpl;
std::vector<Tile> mTiles;

WorldProperties mWorldProperties;
};
