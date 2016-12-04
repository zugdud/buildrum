class FontManager
{

static FontManager *mSingletonInstance;

public:

static FontManager * getInstance();
bool configure(const EnvironmentMediaPropertiesImpl &environmentMediaPropertiesImpl,
               const FontProfileImpl &FontProfileImpl);

FontTextures & getTextures(const std::string & fontProfileName, const std::string & text);


private:

FontManager();
~FontManager();

bool init();
bool loadAllMedia();
bool loadFont(const FontProfile & FontProfile);
void createFontTexture(const std::string & text, const FontProfile & FontProfile);

EnvironmentMediaPropertiesImpl mEnvironmentMediaPropertiesImpl;
FontProfileImpl mFontProfileImpl;

std::map<std::string, FontProfile> mFontProfiles; // fontProfileName->FontProfile
std::map<std::string, TTF_Font * > mFontMap; // fontProfileName->FontManager
std::map<std::string, FontTextures> mFontTextures; // fontProfileName->FontTexture map for all strings

};
