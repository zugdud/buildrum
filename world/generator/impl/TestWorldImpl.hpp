class TestWorldImpl
{
public:

TestWorldImpl();
~TestWorldImpl();

void setWorld(World & world);

private:

void setWorldProperties();

Tile createTile(const int & tileId);
bool isEdge(const int & tileId);

Surface edgeSurface();
Surface defaultSurface();

SurfacePropertiesImpl mSurfacePropertiesImpl;
std::vector<Tile> mTiles;

WorldProperties mWorldProperties;
};
