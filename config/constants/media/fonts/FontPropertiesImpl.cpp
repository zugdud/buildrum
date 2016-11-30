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
    // fontName, fileName
    FontProperties openSansBold = { "OpenSans-Bold", "OpenSans-Bold.ttf"  };
    FontProperties openSansLight = { "OpenSans-Light", "OpenSans-Light.ttf"  };
    FontProperties limelight = { "limelight", "Limelight.ttf"  };

    mFontProperties.push_back(openSansBold);
    mFontProperties.push_back(openSansLight);
    mFontProperties.push_back(limelight);
}

const std::vector<FontProperties> & FontPropertiesImpl::getFontProperties()
{
    return mFontProperties;
}
