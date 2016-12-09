class Tile
{
public:

Tile(const int & tileId);
~Tile();

void setSurface(const Surface & surface);
const Surface & getSurface();

private:

int tileId;
Surface mSurface;

};
