class FontPropertiesImpl
{
public:

FontPropertiesImpl();
~FontPropertiesImpl();

void loadAll();
const std::vector<FontProperties> & getFontProperties();

private:

void setFontProperties();
std::vector<FontProperties> mFontProperties;

};
