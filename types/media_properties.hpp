
// ------------------------------------------------------------------------------
// Media
// ------------------------------------------------------------------------------

struct SpriteSheetProperties
{
    std::string spriteSheetId;
    std::string fileName;
    int rows;
    int columns;
    int spriteSize;
    int spriteCount;
    int sheetPixelWidth;
    int sheetPixelHeight;
    SDL_Color colorKey;
};


struct AudioPlayerProperties
{
    int frequency;
    Uint16 format;
    int channels;
    int chunksize;
    std::string defaultMusicTrackId;
};


struct SoundEffectProperties
{
    std::string soundEffectId;
    std::string fileName;
};

struct MusicTrackProperties
{
    std::string musicTrackId;
    std::string fileName;
};

struct FontProfile
{
    std::string fontProfileName;
    int fontSize;
    std::string filePath;
    SDL_Color fontColor;
};
