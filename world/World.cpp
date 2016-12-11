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
    updateTileRects();
    updateTileLabels();
}

void World::updateTileRects()
{
    SDL_Log("World::updateTileRects \n");
    for (size_t i = 0; i < mTiles.size(); i++)
    {
        mTiles[i].updateRect(mWorldProperties);
    }
}

void World::updateTileLabels()
{
    SDL_Log("World::updateTileLabels \n");
    for (size_t i = 0; i < mTiles.size(); i++)
    {
        mTiles[i].updateLabel();
    }
}

const Tile & World::getTile(const int & tileId)
{
    if (tileId > (mWorldProperties.numTiles - 1))
    {
        SDL_Log("World::getTile -- ERROR: requested tileId out of bounds tileId: %d \n", tileId);
    }
    return mTiles[tileId];
}

const std::vector<Tile> & World::getTiles() const
{
    return mTiles;
}

const WorldProperties & World::getWorldProperties() const
{
    return mWorldProperties;
}
