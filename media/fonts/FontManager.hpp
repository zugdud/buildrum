class FontManager
{

static FontManager *mSingletonInstance;

public:

static FontManager * getInstance();
void configure(const EnvironmentMediaPropertiesImpl &environmentMediaPropertiesImpl,
               const FontPropertiesImpl &fontPropertiesImpl);

const FontTextures & getTextures(const std::string & fontName, const std::string & text);


private:

FontManager();
~FontManager();

init();
loadAllMedia();
void loadFont(const FontProperties & fontProperties);
void createFontTexture(const std::string & text, const FontProperties & fontProperties);

EnvironmentMediaPropertiesImpl mEnvironmentMediaPropertiesImpl;
FontPropertiesImpl mFontPropertiesImpl;

std::map<std::string, FontProperties> mFontProperties; // fontName->FontProperties
std::map<std::string, TTF_Font * > mFontMap; // fontName->FontManager
std::map<std::string, FontTextures> mFontTextures; // fontName->FontTexture map for all strings

};
