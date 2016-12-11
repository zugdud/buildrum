class WorldRenderer
{
public:

WorldRenderer();
~WorldRenderer();

void attach(const Viewport &viewport);
void detatch();

void render();

SDL_Rect calcRect(const int & tileId);

private:

void renderTile(const Tile & tile, const SDL_Rect & tileRect);
void renderSprite(const SpriteProperties & spriteProperties, const SDL_Rect & destRect);

SDL_Renderer *mSDLRenderer;
Camera mCamera;
World mWorld;
bool mAttached;

};
