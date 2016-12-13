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
    updateTileRects(); // TODO
    updateTileLabels();
}

void World::positionUpdate(const SDL_Rect & cameraRect)
{
    SDL_Log("World::positionUpdate \n");
}

void World::zoomFactorUpdate(const double & zoomFactor)
{
    updateTileRects();
    updateTileLabels(); // updates based on new rect
}

void World::updateTileRects()
{
    SDL_Log("World::updateTileRects -- zoomFactor: %f \n",  zoomFactor);
    for (size_t i = 0; i < mTiles.size(); i++)
    {
        mTiles[i].updateRect(mWorldProperties, zoomFactor);
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
