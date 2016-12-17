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

void  createBackgroundTexture(const Viewport &viewport);

bool createBGTexture(const Viewport &viewport);
bool saveScreenshotBMP(std::string filepath, SDL_Window *SDLWindow, SDL_Renderer *SDLRenderer);
void renderBackground();
void renderCamera();
void renderBorder();

void renderLayers(const Tile & tile, const SDL_Rect & rect);
void renderSprite(const SpriteProperties & spriteProperties, const SDL_Rect & destRect);

SDL_Renderer *mSDLRenderer;
SDL_Texture *mBackgroundTexture;
SDL_Rect mBorderRect;

double mScaleRatio;
bool mAttached;


};
