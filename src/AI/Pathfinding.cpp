#include "include/global.hpp"

// search the Pathfinding for the optimal path
void Pathfinding::findPath(const int & startTileId,
                           const int & endTileId,
                           const std::string & aiStrategy)
{
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
            const Tile & neighborTile = World::Instance().getTile(neighborTileId);

            int totalCost = costSoFar[currentTileId] + neighborTile.getWeight(aiStrategy);
            if (!costSoFar.count(neighborTileId) || totalCost < costSoFar[neighborTileId])
            {
                // if we haven't been here yet, add it to the weightedQueue
                weightedQueue.push(neighborTile.getWeight(aiStrategy), neighborTileId);
                cameFrom[neighborTileId] = currentTileId;
                costSoFar[neighborTileId] = totalCost;
                World::Instance().setPath(neighborTileId, aiStrategy, currentTileId);
            }
        }
    }
    // setPath(startTileId, endTileId, aiStrategy, cameFrom);
}

EntityOrientation Pathfinding::getMovementDirection(const int & sourceTileId,
                                                    const int & destinationTileId)
{
    MatrixPosition sourceTile = getMatrixPosition(sourceTileId);
    MatrixPosition destinationTile = getMatrixPosition(destinationTileId);
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
    const int thisColumn = linearIndex / World::Instance().getWorldProperties().rows;
    const int thisRow = linearIndex %  World::Instance().getWorldProperties().rows;
    PointInt pointInt;

    pointInt.x = thisColumn;
    pointInt.y = thisRow;
    return pointInt;
}

int Pathfinding::getLinearIndex(const PointInt & matrixPosition)
{
    int linearIndex = (World::Instance().getWorldProperties().rows * matrixPosition.y) + matrixPosition.x;

    return linearIndex;
}


void Pathfinding::collectNeighbors(const int & tileId,
                                   const std::vector<int> & neighbors)
{
    MatrixPosition tile = getMatrixPosition(tileId);
    const int x = tile.x;
    const int y = tile.y;

    // up
    if (y > 0) // otherwise an underflow occurred, so not a neighbour
    {
        int up = y - 1;
        int neighborTileId = getLinearIndex(x, up);
        neighbors.push_back(neighborTileId);
    }
    // down
    if (y < mTileRows - 1)
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
    if (x < mTileColumns - 1)
    {
        int right = x + 1;
        int neighborTileId = getLinearIndex(right, y);
        neighbors.push_back(neighborTileId);
    }
}
