class World : public CameraObserver
{
public:

World();
~World();

void configure(const WorldProperties & worldProperties, const std::vector<Tile> & tiles);
void updateTileRects();
void updateTileLabels();


void positionUpdate(const SDL_Rect & cameraRect);
void zoomFactorUpdate(const double & zoomFactor);

const Tile & getTile(const int & tileId);
const std::vector<Tile> & getTiles() const;
const WorldProperties & getWorldProperties() const;

private:

WorldProperties mWorldProperties;
std::vector<Tile> mTiles;

};
