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
    // updateTileLabels();
}

void World::positionUpdate()
{
    SDL_Log("World::positionUpdate \n");
}

void World::zoomFactorUpdate()
{
    updateTileRects();
    //  updateTileLabels(); // updates based on new rect
}

void World::updateTileRects()
{
    SDL_Log("World::updateTileRects -- zoomFactor: %f \n",  Camera::Instance().getZoomFactor());

    for (size_t i = 0; i < mTiles.size(); i++)
    {
        mTiles[i].updateRect(mWorldProperties,
                             Camera::Instance().getZoomFactor(),
                             Camera::Instance().getRect());
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
