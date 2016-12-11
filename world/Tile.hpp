class Tile
{
public:

Tile();
~Tile();

void configure(const TileProperties & tileProperties);

void updateRect(const WorldProperties & worldProperties);

const TileProperties & getTileProperties() const;

void setSurface(const Surface & surface);
const Surface & getSurface() const;

const SDL_Rect & getRect() const;

private:

SDL_Rect mRect;

TileProperties mTileProperties;
Surface mSurface;

};
