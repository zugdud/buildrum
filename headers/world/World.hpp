class World : public CameraObserver, public PointEventObserver, public ITimerObserver
{
public:

World();
~World();

void configure(const WorldProperties & worldProperties, const std::vector<Tile> & tiles);
void updateTileRects();
void updateTileLabels();

void eventRaised(const std::string & eventId);
void checkViewableArea();

void positionUpdate();
void zoomFactorUpdate();

const Tile & getTile(const int & tileId) const;
Tile & getTileW(const int & tileId);

const std::vector<Tile> & getTiles() const;
const WorldProperties & getWorldProperties() const;

void pointEventCallback(PointInt pointInt);



void attachInput();
void detatchInput();

void setPath(const int & tileId,
             const std::string & aiStrategy,
             const int & destTileId);

const std::string & getViewportId() const;
const std::string & getId();

void buildTimerComplete(const int & tileId);

private:

WorldProperties mWorldProperties;
std::vector<Tile> mTiles;

};
