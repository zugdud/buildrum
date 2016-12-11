class TestWorldImpl
{
public:

TestWorldImpl();
~TestWorldImpl();

void setWorld(World & world);

private:

void setWorldProperties();
void setTileProperties(Tile & tile);
void setSurfaceProperties(Surface & surface);

SurfacePropertiesImpl mSurfacePropertiesImpl;
std::vector<Tile> mTiles;

WorldProperties mWorldProperties;
};
