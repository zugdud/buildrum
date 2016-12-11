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
    worldProperties.rows = 16;
    worldProperties.columns = 16;
    worldProperties.numTiles = 256;
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
    Surface surface = Surface();

    SurfaceProperties surfaceProperties = mSurfacePropertiesImpl.getSurfaceProperties("field_1");

    //
    // SDL_Log("TestWorldImpl::setSurface -- entityId: %s weight: %d \n",
    //         surfaceProperties.entityProperties.entityId.c_str(),
    //         surfaceProperties.weightValue);
    surface.configure(surfaceProperties);

    return surface;
}
