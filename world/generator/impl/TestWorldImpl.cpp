#include "include/global.hpp"

TestWorldImpl::TestWorldImpl()
{
    SDL_Log("TestWorldImpl::TestWorldImpl construct \n");
    mTileCount = 65536;
    mSurfacePropertiesImpl = ConfigManager::getInstance()->getSurfacePropertiesImpl();
}

TestWorldImpl::~TestWorldImpl()
{

}

void TestWorldImpl::setWorld(World & world)
{
    for (int tileId = 0; tileId < mTileCount; tileId++)
    {
        Tile tile = Tile(tileId);
        setTile(tile);
        mTiles.push_back(tile);
    }
}

void TestWorldImpl::setTile(Tile & tile)
{
    tile.setSurface(Surface());
}

void TestWorldImpl::setSurface(Surface & surface)
{
    surface.configure(mSurfacePropertiesImpl.getSurfaceProperties("grass_1"));
}
