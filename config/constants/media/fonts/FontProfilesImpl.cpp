#include "include/global.hpp"

FontProfileImpl::FontProfileImpl()
{

}

FontProfileImpl::~FontProfileImpl()
{

}

void FontProfileImpl::loadAll()
{
    setFontProfile();
}

void FontProfileImpl::setFontProfile()
{
    int heading_1_FontSize = 48;
    int heading_2_FontSize = 24;
    int heading_3_FontSize = 12;

    SDL_Color white = { 255, 255, 255, 255 };

    // fontProfileName, fontSize, fileName, fontColor
    FontProfile Heading_1_OpenSansBold = { "Heading_1_OpenSansBold", heading_1_FontSize, "OpenSans-Bold.ttf", white };
    FontProfile Heading_2_OpenSansBold = { "Heading_2_OpenSansBold", heading_2_FontSize, "OpenSans-Bold.ttf", white };
    FontProfile Heading_3_OpenSansBold = { "Heading_3_OpenSansBold", heading_3_FontSize, "OpenSans-Bold.ttf", white };

    FontProfile Heading_1_OpenSansLight = { "Heading_1_OpenSansLight", heading_1_FontSize, "OpenSans-Light.ttf", white };
    FontProfile Heading_2_OpenSansLight = { "Heading_2_OpenSansLight", heading_2_FontSize, "OpenSans-Light.ttf", white };
    FontProfile Heading_3_OpenSansLight = { "Heading_3_OpenSansLight", heading_3_FontSize, "OpenSans-Light.ttf", white };

    FontProfile Heading_1_limelight = { "Heading_1_limelight", heading_1_FontSize, "Limelight.ttf", white };
    FontProfile Heading_2_limelight = { "Heading_2_limelight", heading_2_FontSize, "Limelight.ttf", white };
    FontProfile Heading_3_limelight = { "Heading_3_limelight", heading_3_FontSize, "Limelight.ttf", white };

    mFontProfile.push_back(Heading_1_OpenSansBold);
    mFontProfile.push_back(Heading_2_OpenSansBold);
    mFontProfile.push_back(Heading_3_OpenSansBold);

    mFontProfile.push_back(Heading_1_OpenSansLight);
    mFontProfile.push_back(Heading_2_OpenSansLight);
    mFontProfile.push_back(Heading_3_OpenSansLight);

    mFontProfile.push_back(Heading_1_limelight);
    mFontProfile.push_back(Heading_2_limelight);
    mFontProfile.push_back(Heading_3_limelight);
}

const std::vector<FontProfile> & FontProfileImpl::getFontProfiles()
{
    return mFontProfile;
}
