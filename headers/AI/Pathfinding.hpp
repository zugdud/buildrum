class Pathfinding
{

public:

Pathfinding();
~Pathfinding();

void findPath(const int & startTileId,
              const int & endTileId,
              const double & weightModifierRatio,
              const std::string & aiStrategy);

EntityOrientation getMovementDirection(const int & sourceTileId,
                                       const int & destinationTileId);

PointInt getMatrixPosition(const int & linearIndex);
int getLinearIndex(const int & x, const int & y);
void collectNeighbors(const int & tileId,
                      std::vector<int> & neighbors);

private:


};
