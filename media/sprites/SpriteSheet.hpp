class SpriteSheet
{
public:

SpriteSheet();
~SpriteSheet();

bool configure(const EnvironmentMediaPropertiesImpl &environmentMediaPropertiesImpl,
               const SpriteSheetProperties &spriteSheetProperties);
bool loadSpriteSheet();

SDL_Texture * getTexture();
const Sprite & getSprite(const int & spriteId);

private:

void setSprites();
void applyTransparency(SDL_Texture *newTexture, SDL_Surface *formattedSurface);

EnvironmentMediaPropertiesImpl mEnvironmentMediaPropertiesImpl;
SpriteSheetProperties mSpriteSheetProperties;

std::vector<Sprite> mSprites;

SDL_Texture *mTexture;
SDL_Renderer *mSDLRenderer;
};
