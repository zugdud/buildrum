class MinimapRenderer
{
public:

MinimapRenderer();
~MinimapRenderer();

void attach(const Viewport &viewport);
void detatch();

void renderWorld();

SDL_Rect calcRect(const int & tileId);
const bool & isAttached();

private:

void viewportBackground();

void renderText(const Tile & tile);
void drawTile(const Tile & tile);
void renderLayers(const Tile & tile);
void renderSprite(const SpriteProperties & spriteProperties, const SDL_Rect & destRect);

SDL_Renderer *mSDLRenderer;

bool mAttached;

};
