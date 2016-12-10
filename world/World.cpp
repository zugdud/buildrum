#include "include/global.hpp"

World::World()
{

}

World::~World()
{

}

void World::configure(const WorldProperties & worldProperties, const std::vector<Tile> & tiles)
{
    mWorldProperties = worldProperties;
    mTiles = tiles;
}

const Tile & World::getTile(const int & tileId)
{
    if (tileId > (mWorldProperties.numTiles - 1))
    {
        SDL_Log("World::getTile -- ERROR: requested tileId out of bounds tileId: %d \n", tileId);
    }
    return mTiles[tileId];
}

const std::vector<Tile> & World::getTiles()
{
    return mTiles;
}

const WorldProperties & World::getWorldProperties()
{
    return mWorldProperties;
}
