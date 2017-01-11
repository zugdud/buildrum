class SpritePropertiesImpl
{
public:

SpritePropertiesImpl();
~SpritePropertiesImpl();

void loadAll();
const SpriteProperties & getSpriteProperties(const std::string & spriteName) const;

private:

void setCastle_1();
void setCastle_2();
void setIcons_1();

SpriteProperties getSpriteProperties(
    const int & spriteId,
    const std::string & spriteSheetId,
    const SDL_RendererFlip & sdlRendererFlip,
    const double & angle);

std::map<std::string, SpriteProperties> mSpriteProperties;

};
