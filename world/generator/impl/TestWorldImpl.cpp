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
        mTiles.push_back(createTile(tileId));
    }

    world.configure(mWorldProperties, mTiles);
}


Tile TestWorldImpl::createTile(const int & tileId)
{
    Tile tile = Tile();

    tile.configure(tileId);
    tile.setSurface(createSurface());

    return tile;
}

Surface TestWorldImpl::createSurface()
{
    Surface suface = Surface();

    SurfaceProperties surfaceProperties = mSurfacePropertiesImpl.getSurfaceProperties("field_1");

    SDL_Log("TestWorldImpl::setSurface -- entityId: %s weight: %d \n",
            surfaceProperties.entityProperties.entityId.c_str(),
            surfaceProperties.weightValue);
    surface.configure(surfaceProperties);

    return surface;
}
