#include "include/global.hpp"

TestWorldImpl::TestWorldImpl()
{
    SDL_Log("TestWorldImpl::TestWorldImpl construct \n");
    setWorldProperties();
    mSurfacePropertiesImpl = ConfigManager::getInstance()->getSurfacePropertiesImpl();
}

TestWorldImpl::~TestWorldImpl()
{

}

void TestWorldImpl::setWorldProperties()
{
    WorldProperties worldProperties;

    worldProperties.worldId = "testWorld";
    worldProperties.viewportId = "gameView";
    worldProperties.rows = 64;
    worldProperties.columns = 64;
    worldProperties.numTiles = 4096;
    worldProperties.textureSize = 32;

    mWorldProperties = worldProperties;
}

void TestWorldImpl::setWorld(World & world)
{
    for (int tileId = 0; tileId < mWorldProperties.numTiles; tileId++)
    {
        mTiles.push_back(createTile(tileId));
    }

    world.configure(mWorldProperties, mTiles);
}


Tile TestWorldImpl::createTile(const int & tileId)
{
    Tile tile = Tile();

    TileProperties tileProperties;

    SDL_Color red = { 255, 0, 0, 255 };
    SDL_Color blue = { 0, 0, 255, 255 };

    tileProperties.tileId = tileId;
    tileProperties.drawBorder = true;
    tileProperties.borderColor = red;
    tileProperties.fillBackground = true;
    tileProperties.backgroundColor = blue;
    tileProperties.showTileIdText = true;
    tileProperties.fontProfileName = "Heading_3_OpenSansLight";

    tile.configure(tileProperties);

    if (isEdge(tileId))
    {
        tile.setSurface(edgeSurface());
    }
    else
    {
        tile.setSurface(defaultSurface());
    }

    return tile;
}

Surface TestWorldImpl::defaultSurface()
{
    Surface surface = Surface();

    surface.configure(mSurfacePropertiesImpl.getSurfaceProperties("brick_1"));

    return surface;
}

Surface TestWorldImpl::edgeSurface()
{
    Surface surface = Surface();

    surface.configure(mSurfacePropertiesImpl.getSurfaceProperties("water_1"));

    return surface;
}

bool TestWorldImpl::isEdge(const int & tileId)
{
    int col = tileId % mWorldProperties.columns;
    int row = tileId / mWorldProperties.rows;

    if (col == 0 || row == 0)
    {
        return true;
    }
    if (row % 16 == 0 || col % 16 == 0)
    {
        return true;
    }
    if (row == (mWorldProperties.rows - 1) || col == (mWorldProperties.columns - 1))
    {
        return true;
    }
    return false;
}
