class Tile
{
public:

Tile();
~Tile();

void configure(const int & tileId);

void setSurface(const Surface & surface);
const Surface & getSurface();

private:

int mTileId;
Surface mSurface;

};
