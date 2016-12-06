class SpriteSheet
{
public:
SpriteSheet();
~SpriteSheet();


private:

SpriteSheetProperties mSpriteSheetProperties;

std::vector<Sprite> mSprites;
};
