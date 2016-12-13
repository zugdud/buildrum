class World : public CameraObserver
{
public:

World();
~World();

void configure(const WorldProperties & worldProperties, const std::vector<Tile> & tiles);
void updateTileRects();
void updateTileLabels();


void positionUpdate();
void zoomFactorUpdate();

const Tile & getTile(const int & tileId);
const std::vector<Tile> & getTiles() const;
const WorldProperties & getWorldProperties() const;

private:

WorldProperties mWorldProperties;
std::vector<Tile> mTiles;

};
