class Tile
{
public:

Tile();
~Tile();

void configure(const TileProperties & tileProperties);
void updateRect(const WorldProperties & worldProperties, const double & zoomFactor, const SDL_Rect & cameraRect);
void setSurface(const Surface & surface);
void setBuildableObject(const BuildableObject & buildableObject);

void setViewableArea();
void updateLabel();

const Surface &getSurface() const;
const BuildableObject &getBuildableObject() const;

const TileProperties & getTileProperties() const;
const SDL_Rect & getRect() const;
const TextLabel & getTextLabel() const;

const bool & isViewableArea() const;

private:

SDL_Rect mRect;
TileProperties mTileProperties;

BuildableObject mBuildableObject;
Surface mSurface;

TextLabel mTextLabel;
bool mViewableArea;
};
