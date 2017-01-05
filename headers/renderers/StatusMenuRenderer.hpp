class StatusMenuRenderer : public IStatusMenuRenderer, public BaseRenderer
{
public:

StatusMenuRenderer();
~StatusMenuRenderer();

void attach(const Viewport &viewport);
void detatch();

void render();

const bool & isAttached();

private:

void renderBackground();
void renderBorder();

void setLayout();
void drawBorders();
void renderCreditsRemaining(const SDL_Rect & cellRect);
SDL_Rect getCellRect(const int & offsetX, const int & offsetY, const double & scale);
std::string intToStr(const int & value);
void renderBorder(const SDL_Rect & cellRect);
void renderBackground(const SDL_Rect & cellRect);
void renderText(const std::string & text, const SDL_Rect & cellRect);

SDL_Rect mBorder;
SDL_Rect mHeading;
SDL_Rect mCreditsRemain;

bool mAttached;
std::string mLabelTextProfile;

};
