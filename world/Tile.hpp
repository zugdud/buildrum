class Tile
{
public:

Tile();
~Tile();

void configure(const int & tileId);

void setSurface(const Surface & surface);
const Surface & getSurface() const;

private:

int mTileId;
Surface mSurface;

};
