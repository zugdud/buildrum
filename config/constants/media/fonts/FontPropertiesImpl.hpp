class FontProperties
{
public:

FontPropertiesImpl();
~FontPropertiesImpl();

void loadAll();

private:

void setFontProperties();
std::vector<FontProperties> mFontProperties;

};
