class Tile
{
public:

Tile();
~Tile();

void configure(const TileProperties & tileProperties);

void updateRect(const WorldProperties & worldProperties, const double & zoomFactor);

const TileProperties & getTileProperties() const;

void setSurface(const Surface & surface);
const Surface & getSurface() const;

const SDL_Rect & getRect() const;
const TextLabel & getTextLabel() const;

void updateLabel();

private:

SDL_Rect mRect;
TileProperties mTileProperties;
Surface mSurface;

TextLabel mTextLabel;

};
