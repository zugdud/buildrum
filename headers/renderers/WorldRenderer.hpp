class WorldRenderer : public IWorldRenderer, public BaseRenderer
{
public:

WorldRenderer();
~WorldRenderer();

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

bool mAttached;

};
