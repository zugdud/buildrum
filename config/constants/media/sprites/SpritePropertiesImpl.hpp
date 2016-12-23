class SpritePropertiesImpl
{
public:

SpritePropertiesImpl();
~SpritePropertiesImpl();

void loadAll();
const SpriteProperties & SpritePropertiesImpl::getSpriteProperties(const std::string & spriteName);

private:

void setCastle_1();
void setCastle_2();

SpriteProperties getSpriteProperties(
    const int & spriteId,
    const std::string & spriteSheetId,
    const SDL_RendererFlip & sdlRendererFlip,
    const double & angle,
    );

std::map<std::string, SpriteProperties> mSpriteProperties;

};
