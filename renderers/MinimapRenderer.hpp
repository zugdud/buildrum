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

void viewportBackground();

void renderLayers(const Tile & tile);
void renderSprite(const SpriteProperties & spriteProperties, const SDL_Rect & destRect);

SDL_Renderer *mSDLRenderer;

bool mAttached;

};
