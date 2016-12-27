class SelectedActionMenuRenderer : public IRendererSelectedAction
{
public:

SelectedActionMenuRenderer();
~SelectedActionMenuRenderer();

void attach(const Viewport &viewport);
void detatch();

void render();

const bool & isAttached();

private:

void renderBackground();
void renderBorder();
void renderSelectedAction();

void renderSprite(const SpriteProperties & spriteProperties, const SDL_Rect & destRect);

SDL_Renderer *mSDLRenderer;
SDL_Rect mBorder;

bool mAttached;

};
