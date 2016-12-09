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
    if (tileId <= (mWorldProperties.numTiles - 1))
    {
        return mTiles[tileId];
    }
    else
    {
        SDL_Log("World::getTile -- requested tileId out of bounds tileId: %d \n", tileId);
    }
}
