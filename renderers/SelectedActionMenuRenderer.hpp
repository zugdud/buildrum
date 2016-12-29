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

void setLayout();
SDL_Rect getCellRect(const int & offsetX, const int & offsetY, const double & scale);

std::string intToStr(const int & value);
void renderText(const std::string & text, const SDL_Rect & cellRect);
void renderBackground(const SDL_Rect & cellRect);
void renderBorder(const SDL_Rect & cellRect);
void renderSelectedAction(const SDL_Rect & cellRect);

void drawBorders();
void renderResourceCost(const SDL_Rect & cellRect);
void renderObjectName(const SDL_Rect & cellRect);


void renderSprite(const SpriteProperties & spriteProperties, const SDL_Rect & destRect);

SDL_Renderer *mSDLRenderer;
SDL_Rect mBorder;

SDL_Rect mHeading;
SDL_Rect mIcon;
SDL_Rect mName;
SDL_Rect mCost;

bool mAttached;
std::string mLabelTextProfile;

};
