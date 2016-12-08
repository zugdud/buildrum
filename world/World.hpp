class World
{
public:

World();
~World();

void configure(const std::vector<Tile> & tiles);

private:

std::vector<Tile> mTiles;

};
