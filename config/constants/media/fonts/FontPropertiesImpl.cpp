#include "include/global.hpp"

FontPropertiesImpl::FontPropertiesImpl()
{

}

FontPropertiesImpl::~FontPropertiesImpl()
{

}

void FontPropertiesImpl::loadAll()
{
    setFontProperties();
}

void FontPropertiesImpl::setFontProperties()
{
    int heading_1_FontSize = 48;
    int heading_2_FontSize = 24;
    int heading_3_FontSize = 12;

    SDL_Color black = { 0, 0, 0, 255 };

    // fontName, fontSize, fileName, fontColor
    FontProperties Heading_1_OpenSansBold = { "Heading_1_OpenSansBold", heading_1_FontSize, "OpenSans-Bold.ttf", black };
    FontProperties Heading_2_OpenSansBold = { "Heading_2_OpenSansBold", heading_2_FontSize, "OpenSans-Bold.ttf", black };
    FontProperties Heading_3_OpenSansBold = { "Heading_3_OpenSansBold", heading_3_FontSize, "OpenSans-Bold.ttf", black };

    FontProperties Heading_1_OpenSansLight = { "Heading_1_OpenSansLight", heading_1_FontSize, "OpenSans-Light.ttf", black };
    FontProperties Heading_2_OpenSansLight = { "Heading_2_OpenSansLight", heading_2_FontSize, "OpenSans-Light.ttf", black };
    FontProperties Heading_3_OpenSansLight = { "Heading_3_OpenSansLight", heading_3_FontSize, "OpenSans-Light.ttf", black };

    FontProperties Heading_1_limelight = { "Heading_1_limelight", heading_1_FontSize, "Limelight.ttf", black };
    FontProperties Heading_2_limelight = { "Heading_2_limelight", heading_2_FontSize, "Limelight.ttf", black };
    FontProperties Heading_3_limelight = { "Heading_3_limelight", heading_3_FontSize, "Limelight.ttf", black };

    mFontProperties.push_back(Heading_1_OpenSansBold);
    mFontProperties.push_back(Heading_2_OpenSansBold);
    mFontProperties.push_back(Heading_3_OpenSansBold);

    mFontProperties.push_back(Heading_1_OpenSansLight);
    mFontProperties.push_back(Heading_2_OpenSansLight);
    mFontProperties.push_back(Heading_3_OpenSansLight);

    mFontProperties.push_back(Heading_1_limelight);
    mFontProperties.push_back(Heading_2_limelight);
    mFontProperties.push_back(Heading_3_limelight);
}

const std::vector<FontProperties> & FontPropertiesImpl::getFontProperties()
{
    return mFontProperties;
}
