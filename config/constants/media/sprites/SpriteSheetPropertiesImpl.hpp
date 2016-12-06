class SpriteSheetPropertiesImpl
{
public:

SpriteSheetPropertiesImpl();
~SpriteSheetPropertiesImpl();

void loadAll();
const std::vector<SpriteSheetProperties> & getSpriteSheetProperties();

private:

void setSpriteSheetProperties();
std::vector<SpriteSheetProperties> mSpriteSheetProperties;

};
