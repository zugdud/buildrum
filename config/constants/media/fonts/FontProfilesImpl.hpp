class FontProfileImpl
{
public:

FontProfileImpl();
~FontProfileImpl();

void loadAll();
const std::vector<FontProfile> & getFontProfiles();

private:

void setFontProfile();
std::vector<FontProfile> mFontProfile;

};
