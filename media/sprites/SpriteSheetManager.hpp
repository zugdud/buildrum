class SpriteSheetManager
{


public:

static SpriteSheetManager& Instance()
{
    static SpriteSheetManager instance;

    return instance;
}

bool configure(const EnvironmentMediaPropertiesImpl &environmentMediaPropertiesImpl,
               const SpriteSheetPropertiesImpl &spriteSheetPropertiesImpl);

protected:

SpriteSheetManager();
SpriteSheetManager(const SpriteSheetManager *);
SpriteSheetManager& operator=(const SpriteSheetManager *);
~SpriteSheetManager();

private:

bool loadSpriteSheets();

EnvironmentMediaPropertiesImpl mEnvironmentMediaPropertiesImpl;
SpriteSheetPropertiesImpl mSpriteSheetPropertiesImpl;

std::map<std::string, SpriteSheet> mSpriteSheets; // spriteSheetId->scene
};
