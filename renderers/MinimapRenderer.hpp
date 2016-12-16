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

void renderCamera();
void renderBorder();

void renderLayers(const Tile & tile, const SDL_Rect & rect);
void renderSprite(const SpriteProperties & spriteProperties, const SDL_Rect & destRect);

SDL_Renderer *mSDLRenderer;

SDL_Rect mBorderRect;
bool mAttached;

std::vector<SDL_Rect> mMinimapRects;

double mScaleRatio;
};
