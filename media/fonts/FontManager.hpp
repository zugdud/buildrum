class FontManager
{

static FontManager *mSingletonInstance;

public:

static FontManager * getInstance();
void configure(const EnvironmentMediaPropertiesImpl &environmentMediaPropertiesImpl,
               const FontProfileImpl &FontProfileImpl);

const FontTextures & getTextures(const std::string & fontProfileName, const std::string & text);


private:

FontManager();
~FontManager();

bool init();
void loadAllMedia();
void loadFont(const FontProfile & FontProfile);
void createFontTexture(const std::string & text, const FontProfile & FontProfile);

EnvironmentMediaPropertiesImpl mEnvironmentMediaPropertiesImpl;
FontProfileImpl mFontProfileImpl;

std::map<std::string, FontProfile> mFontProfile; // fontProfileName->FontProfile
std::map<std::string, TTF_Font * > mFontMap; // fontProfileName->FontManager
std::map<std::string, FontTextures> mFontTextures; // fontProfileName->FontTexture map for all strings

};
