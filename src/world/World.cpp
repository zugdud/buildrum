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
    if (tileId > (mWorldProperties.numTiles - 1) || tileId < 0)
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
    if (Player::Instance().getAction() == BUILD_ACTION)
    {
        const SDL_Rect & cameraRect = Camera::Instance().getRect();
        const double & zoomFactor = Camera::Instance().getZoomFactor();

        const int worldPosX = ceil((pointInt.x + cameraRect.x) / zoomFactor);
        const int worldPosY = ceil((pointInt.y + cameraRect.y) / zoomFactor);

        const int tileX = (worldPosX / mWorldProperties.textureSize);
        const int tileY = (worldPosY / mWorldProperties.textureSize);

        const int tileId = (mWorldProperties.rows * tileY) + tileX;

        SDL_Log("World::pointEventCallback -- pointInt: [x: %d y: %d] cameraRect: [x: %d y: %d] worldPos: [x: %d y: %d] TilePos: [x: %d y: %d] tileId: %d zoomFactor: %f\n",
                pointInt.x,
                pointInt.y,
                cameraRect.x,
                cameraRect.y,
                worldPosX,
                worldPosY,
                tileX,
                tileY,
                tileId,
                zoomFactor);


        TimerManager::Instance().startBuildTimer(tileId);
    }
    else
    {
        SDL_Log("World::pointEventCallback -- MOVE MODE set, filtering build event \n");
    }
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

void World::setPath(const int & tileId,
                    const std::string & aiStrategy,
                    const int & destTileId)
{
    // SDL_Log("World::setPath -- setting path: [tileId: %s aiStrategy: %s] \n", tileId.c_str(), aiStrategy.c_str());
    mTiles[tileId].setPath(aiStrategy, destTileId);
}

void World::buildTimerComplete(const int & tileId)
{
    SDL_Log("World::buildTimerComplete -- tileId: %d \n", tileId);

    if (tileId > (mWorldProperties.numTiles - 1) || tileId < 0)
    {
        SDL_Log("World::buildObject -- ERROR: requested tileId out of bounds tileId: %d \n", tileId);

    }
    else
    {

        const BuildableObjectProperties & buildableObjectProperties = Player::Instance().getSelectedBuildableObjectProperties();

        BuildableObject buildableObject;

        buildableObject.configure(buildableObjectProperties);

        Tile tile = mTiles[tileId];

        tile.setBuildableObject(buildableObject);

        mTiles[tileId] = tile;
    }
}
