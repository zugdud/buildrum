class MinimapRenderer : public IMinimapRenderer
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

void renderText(const Tile & tile);
void renderAtlasSurface(const Tile & tile, const SDL_Rect & destRect);
void renderSprite(const SpriteProperties & spriteProperties, const SDL_Rect & destRect);

SDL_Renderer *mSDLRenderer;
SDL_Texture *mBackgroundTexture;

SDL_Rect mMinimap;
SDL_Rect mBorder;

int mMinimapTileSize;
double mScaleRatio;
bool mAttached;

};
