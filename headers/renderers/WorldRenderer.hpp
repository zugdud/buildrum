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

void cycleColor(unsigned char & color, const int & step);
void highlightTileBorder(const Tile & tile);
void renderActionBar(const Tile & tile);

void renderText(const Tile & tile);
void renderLayers(const Tile & tile);

bool mAttached;
SDL_Color mBorderColor;

};
