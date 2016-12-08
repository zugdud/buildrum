#include "include/global.hpp"

TestWorldImpl::TestWorldImpl()
{
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
        mTiles.push_back(setTile(Tile(tileId)));
    }
}

void TestWorldImpl::setTile(Tile & tile)
{
    tile.setSurface(Surface());
}

void TestWorldImpl::setSurface(Surface & surface)
{
    surface.configure(mSurfaceProperties.getSurfaceProperties("grass_1"));
}
