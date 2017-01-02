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
    checkViewableArea();
    // updateTileLabels();
}

void World::positionUpdate()
{
    updateTileRects();
    checkViewableArea();
}

void World::zoomFactorUpdate()
{
    updateTileRects();
    checkViewableArea();
    //  updateTileLabels(); // updates based on new rect
}

void World::eventRaised(const std::string & eventId)
{
    SDL_Log("World::eventRaised -- eventId: %s \n", eventId.c_str());
}

void World::checkViewableArea()
{
    for (size_t i = 0; i < mTiles.size(); i++)
    {
        mTiles[i].setViewableArea();
    }
}

void World::updateTileRects()
{
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

void World::pointEventCallback(PointInt pointInt)
{
    SDL_Log("World::pointEventCallback -- [x: %d y: %d] \n", pointInt.x, pointInt.y);
}

const std::string & World::getViewportId() const
{
    return mWorldProperties.viewportId;
}

const std::string &  World::getId()
{
    return mWorldProperties.worldId;
}

void World::attachInput()
{
    SDL_Log("World::attachInput -- attaching world to input manager \n");
    InputEventManager::getInstance()->registerPointEventObserver(this);
}

void World::detatchInput()
{
    SDL_Log("World::detatchInput -- removing world from input manager \n");
    InputEventManager::getInstance()->removePointEventObserver(mWorldProperties.worldId);
}
