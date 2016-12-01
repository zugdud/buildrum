class FontProfileImpl
{
public:

FontProfileImpl();
~FontProfileImpl();

void loadAll();
const std::vector<FontProfile> & getFontProfile();

private:

void setFontProfile();
std::vector<FontProfile> mFontProfile;

};
