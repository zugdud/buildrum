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
        Tile tile;
        tile.configure(tileId);
        setTile(tile);
        mTiles.push_back(tile);
    }

    world.configure(mWorldProperties, mTiles);
}


void TestWorldImpl::setTile(Tile & tile)
{
    tile.setSurface(Surface());
}

void TestWorldImpl::setSurface(Surface & surface)
{
    surface.configure(mSurfacePropertiesImpl.getSurfaceProperties("field_1"));
}
