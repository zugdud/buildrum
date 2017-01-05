class MinimapRenderer : public IMinimapRenderer, public BaseRenderer
{
public:

MinimapRenderer();
~MinimapRenderer();

void attach(const Viewport &viewport);
void detatch();

void render();

SDL_Rect calcRect(const int & tileId);
const bool & isAttached();

private:

void calcScale();
void buildAtlas();
void createAtlasTexture();

void renderBackground();
void renderCamera();
void renderBorder();

void renderAtlasSurface(const Tile & tile, const SDL_Rect & destRect);

SDL_Texture *mBackgroundTexture;

SDL_Rect mMinimap;
SDL_Rect mBorder;

int mMinimapTileSize;
double mScaleRatio;
bool mAttached;

};
