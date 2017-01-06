class Pathfinding
{

public:

Pathfinding();
~Pathfinding();

void findPath(const int & startTileId,
              const int & endTileId,
              const std::string & aiStrategy);

EntityOrientation getMovementDirection(const int & sourceTileId,
                                       const int & destinationTileId);

PointInt getMatrixPosition(const int & linearIndex);
int getLinearIndex(const PointInt & matrixPosition);
void collectNeighbors(const int & tileId,
                      const std::vector<int> & neighbors);

private:


};
