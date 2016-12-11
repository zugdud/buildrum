class Tile
{
public:

Tile();
~Tile();

void configure(const TileProperties & tileProperties);

const TileProperties & getTileProperties() const;

void setSurface(const Surface & surface);
const Surface & getSurface() const;

private:

TileProperties mTileProperties;
Surface mSurface;

};
