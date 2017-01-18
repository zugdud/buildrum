#include "include/global.hpp"

Pathfinding::Pathfinding()
{

}

Pathfinding::~Pathfinding()
{

}

// search the Pathfinding for the optimal path
void Pathfinding::findPath(const int & startTileId,
                           const int & endTileId,
                           const double & weightModifierRatio,
                           const std::string & aiStrategy)
{

    World *world = WorldManager::Instance().getWorldPtr();

    std::map<int, int> cameFrom; // neighborTileId, current tileId
    std::map<int, int> costSoFar;    // total cost so far for the path from startTileId
    std::vector<int> neighbors; // vec of the neighboring tileIds

    WeightedQueue weightedQueue;
    weightedQueue.push(0, startTileId); // Lowest weight item moves to the front of the queue
    costSoFar[startTileId] = 0;
    cameFrom[startTileId] = startTileId;

    while (!weightedQueue.empty())
    {
        // current tile we are working with
        int currentTileId = weightedQueue.get();

        // exit if we've reached the goal tile
        if (currentTileId == endTileId)
        {
            break;
        }

        // get all the neighbors for this position
        neighbors.clear();
        collectNeighbors(currentTileId, neighbors);
        for (size_t i = 0; i < neighbors.size(); i++)
        {
            int neighborTileId = neighbors[i];
            Tile & neighborTile = world->getTileW(neighborTileId);

            int neighborTileWeight = neighborTile.getSurface().getSurfaceProperties().weightValue * weightModifierRatio;
            int totalCost = costSoFar[currentTileId] + neighborTileWeight;
            if (!costSoFar.count(neighborTileId) || totalCost < costSoFar[neighborTileId])
            {
                // if we haven't been here yet, add it to the weightedQueue
                weightedQueue.push(neighborTileWeight, neighborTileId);
                cameFrom[neighborTileId] = currentTileId;
                costSoFar[neighborTileId] = totalCost;
                neighborTile.setPath(aiStrategy, currentTileId);
            }
        }
    }
}

EntityOrientation Pathfinding::getMovementDirection(const int & sourceTileId,
                                                    const int & destinationTileId)
{
    PointInt sourceTile = getMatrixPosition(sourceTileId);
    PointInt destinationTile = getMatrixPosition(destinationTileId);
    EntityOrientation orientation;

    if (destinationTile.y < sourceTile.y)
    {
        orientation = UP;
    }
    if (destinationTile.y > sourceTile.y)
    {
        orientation = DOWN;
    }
    if (destinationTile.x < sourceTile.x)
    {
        orientation = LEFT;
    }
    if (destinationTile.x > sourceTile.x)
    {
        orientation = RIGHT;
    }
    return orientation;
}

PointInt Pathfinding::getMatrixPosition(const int & linearIndex)
{
    const int thisColumn = linearIndex /  WorldManager::Instance().getWorld().getWorldProperties().rows;
    const int thisRow = linearIndex % WorldManager::Instance().getWorld().getWorldProperties().rows;
    PointInt pointInt;

    pointInt.x = thisColumn;
    pointInt.y = thisRow;
    return pointInt;
}

int Pathfinding::getLinearIndex(const int & x, const int & y)
{
    int linearIndex = (WorldManager::Instance().getWorld().getWorldProperties().rows * y) + x;

    return linearIndex;
}


void Pathfinding::collectNeighbors(const int & tileId,
                                   std::vector<int> & neighbors)
{
    PointInt point = getMatrixPosition(tileId);
    const int x = point.x;
    const int y = point.y;

    // up
    if (y > 0) // otherwise an underflow occurred, so not a neighbour
    {
        int up = y - 1;
        int neighborTileId = getLinearIndex(x, up);
        neighbors.push_back(neighborTileId);
    }
    // down
    if (y < WorldManager::Instance().getWorld().getWorldProperties().rows - 1)
    {
        int down = y + 1;
        int neighborTileId = getLinearIndex(x, down);
        neighbors.push_back(neighborTileId);
    }
    // left
    if (x > 0)
    {
        int left = x - 1;
        int neighborTileId = getLinearIndex(left, y);
        neighbors.push_back(neighborTileId);
    }
    // right
    if (x < WorldManager::Instance().getWorld().getWorldProperties().columns - 1)
    {
        int right = x + 1;
        int neighborTileId = getLinearIndex(right, y);
        neighbors.push_back(neighborTileId);
    }
}
