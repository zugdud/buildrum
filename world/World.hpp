class World
{
public:

World();
~World();

void configure(const WorldProperties & worldProperties, const std::vector<Tile> & tiles);

const Tile & getTile(const int & tileId);
const std::vector<Tile> & getTiles();
const WorldProperties & getWorldProperties();

private:

WorldProperties mWorldProperties;
std::vector<Tile> mTiles;

};
