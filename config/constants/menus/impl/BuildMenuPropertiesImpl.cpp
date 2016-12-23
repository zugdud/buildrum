#include "include/global.hpp"

BuildMenuPropertiesImpl::BuildMenuPropertiesImpl()
{

}

BuildMenuPropertiesImpl::~BuildMenuPropertiesImpl()
{

}

void BuildMenuPropertiesImpl::setProperties()
{
    SDL_Log("BuildMenuPropertiesImpl::loadAll -- loading configuration ...\n");
    setUIMenuProperties();
    setButtonProperties();
    setUILabelProperties();
}

const UIMenuProperties & BuildMenuPropertiesImpl::getUIMenuProperties() const
{
    return mUIMenuProperties;
}
const std::vector<UIButtonProperties> & BuildMenuPropertiesImpl::getUIButtonProperties()
{
    return mUIButtonProperties;
}

const std::vector<UILabelProperties> & BuildMenuPropertiesImpl::getUILabelProperties()
{
    return mUILabelProperties;
}

void BuildMenuPropertiesImpl::setUIMenuProperties()
{
    SDL_Color blue = { 0, 0, 255, 255 };
    SDL_Color green = { 0, 255, 0, 255 };

    SpriteProperties spriteProperties = { 195, "castle_1", SDL_FLIP_NONE, 0 };
    // UIRenderCellDetails: backgroundColor, outlineColor, showBorderColor, showBackgroundColor, backgroundSpriteId, showbackgroundSprite
    UIRenderCellDetails gridCD = { blue, green, true, true, spriteProperties, false };

    UIMenuProperties uiMenuProperties;

    uiMenuProperties.uiMenuId = "BuildMenu";
    uiMenuProperties.viewportId = "gameView";
    uiMenuProperties.rows = 4;
    uiMenuProperties.columns = 4;
    uiMenuProperties.xPadding = 20;
    uiMenuProperties.yPadding = 20;
    uiMenuProperties.uiRenderCellDetails = gridCD;
    uiMenuProperties.hidden = true;

    mUIMenuProperties = uiMenuProperties;
}

void BuildMenuPropertiesImpl::setButtonProperties()
{
    // orderId, buttonId, xPadding, yPadding, actionId, defaultButtonState, isSpacer

    UIButtonProperties build1 = { 1, "build1", 20, 20, "build1", "buttonAvailable", false };
    UIButtonProperties build2 = { 2, "build2", 20, 20, "build2", "buttonAvailable", false };
    UIButtonProperties build3 = { 3, "build3", 20, 20, "build3", "buttonAvailable", false };
    UIButtonProperties build4 = { 4, "build4", 20, 20, "build4", "buttonAvailable", false };
    UIButtonProperties build5 = { 5, "build5", 20, 20, "build5", "buttonAvailable", false };
    UIButtonProperties build6 = { 6, "build6", 20, 20, "build6", "buttonAvailable", false };
    UIButtonProperties build7 = { 7, "build7", 20, 20, "build7", "buttonAvailable", false };
    UIButtonProperties build8 = { 8, "build8", 20, 20, "build8", "buttonAvailable", false };
    UIButtonProperties build9 = { 9, "build9", 20, 20, "build9", "buttonAvailable", false };
    UIButtonProperties build10 = { 10, "build10", 20, 20, "build10", "buttonAvailable", false };
    UIButtonProperties build11 = { 11, "build11", 20, 20, "build11", "buttonAvailable", false };
    UIButtonProperties build12 = { 12, "build12", 20, 20, "build12", "buttonAvailable", false };
    UIButtonProperties build13 = { 13, "build13", 20, 20, "build13", "buttonAvailable", false };
    UIButtonProperties build14 = { 14, "build14", 20, 20, "build14", "buttonAvailable", false };
    UIButtonProperties build15 = { 15, "build15", 20, 20, "build15", "buttonAvailable", false };
    UIButtonProperties build16 = { 16, "build16", 20, 20, "build16", "buttonAvailable", false };

    BaseMenuProperties::setUIButtonStateProperties("build1", 96, "castle_2");
    BaseMenuProperties::setUIButtonStateProperties("build2", 112, "castle_2");
    BaseMenuProperties::setUIButtonStateProperties("build3", 99, "castle_2");
    BaseMenuProperties::setUIButtonStateProperties("build4", 115, "castle_2");
    BaseMenuProperties::setUIButtonStateProperties("build5", 128, "castle_2");
    BaseMenuProperties::setUIButtonStateProperties("build6", 146, "castle_2");
    BaseMenuProperties::setUIButtonStateProperties("build7", 133, "castle_1");
    BaseMenuProperties::setUIButtonStateProperties("build8", 149, "castle_1");
    BaseMenuProperties::setUIButtonStateProperties("build9", 100, "castle_1");
    BaseMenuProperties::setUIButtonStateProperties("build10", 116, "castle_1");
    BaseMenuProperties::setUIButtonStateProperties("build11", 129, "castle_1");
    BaseMenuProperties::setUIButtonStateProperties("build12", 131, "castle_1");
    BaseMenuProperties::setUIButtonStateProperties("build13", 134, "castle_1");
    BaseMenuProperties::setUIButtonStateProperties("build14", 150, "castle_1");
    BaseMenuProperties::setUIButtonStateProperties("build15", 234, "castle_1");
    BaseMenuProperties::setUIButtonStateProperties("build16", 233, "castle_1");

    mUIButtonProperties.push_back(build1);
    mUIButtonProperties.push_back(build2);
    mUIButtonProperties.push_back(build3);
    mUIButtonProperties.push_back(build4);
    mUIButtonProperties.push_back(build5);
    mUIButtonProperties.push_back(build6);
    mUIButtonProperties.push_back(build7);
    mUIButtonProperties.push_back(build8);
    mUIButtonProperties.push_back(build9);
    mUIButtonProperties.push_back(build10);
    mUIButtonProperties.push_back(build11);
    mUIButtonProperties.push_back(build12);
    mUIButtonProperties.push_back(build13);
    mUIButtonProperties.push_back(build14);
    mUIButtonProperties.push_back(build15);
    mUIButtonProperties.push_back(build16);
}

void BuildMenuPropertiesImpl::setUILabelProperties()
{
    // orderId, labelText, fontId, xPadding, yPadding, isSpacer. alignment
    UILabelProperties build1 = { 1, "Build 1", "Heading_3_OpenSansLight", 10, 10, false, "center" };
    UILabelProperties build2 = { 2, "Build 2", "Heading_3_OpenSansLight", 10, 10, false, "center" };
    UILabelProperties build3 = { 3, "Build 3", "Heading_3_OpenSansLight", 10, 10, false, "center" };
    UILabelProperties build4 = { 4, "Build 4", "Heading_3_OpenSansLight", 10, 10, false, "center" };
    UILabelProperties build5 = { 5, "Build 5", "Heading_3_OpenSansLight", 10, 10, false, "center" };
    UILabelProperties build6 = { 6, "Build 6", "Heading_3_OpenSansLight", 10, 10, false, "center" };
    UILabelProperties build7 = { 7, "Build 7", "Heading_3_OpenSansLight", 10, 10, false, "center" };
    UILabelProperties build8 = { 8, "Build 8", "Heading_3_OpenSansLight", 10, 10, false, "center" };
    UILabelProperties build9 = { 9, "Build 9", "Heading_3_OpenSansLight", 10, 10, false, "center" };
    UILabelProperties build10 = { 10, "Build 10", "Heading_3_OpenSansLight", 10, 10, false, "center" };
    UILabelProperties build11 = { 11, "Build 11", "Heading_3_OpenSansLight", 10, 10, false, "center" };
    UILabelProperties build12 = { 12, "Build 12", "Heading_3_OpenSansLight", 10, 10, false, "center" };
    UILabelProperties build13 = { 13, "Build 13", "Heading_3_OpenSansLight", 10, 10, false, "center" };
    UILabelProperties build14 = { 14, "Build 14", "Heading_3_OpenSansLight", 10, 10, false, "center" };
    UILabelProperties build15 = { 15, "Build 15", "Heading_3_OpenSansLight", 10, 10, false, "center" };
    UILabelProperties build16 = { 16, "Build 16", "Heading_3_OpenSansLight", 10, 10, false, "center" };

    mUILabelProperties.push_back(build1);
    mUILabelProperties.push_back(build2);
    mUILabelProperties.push_back(build3);
    mUILabelProperties.push_back(build4);
    mUILabelProperties.push_back(build5);
    mUILabelProperties.push_back(build6);
    mUILabelProperties.push_back(build7);
    mUILabelProperties.push_back(build8);
    mUILabelProperties.push_back(build9);
    mUILabelProperties.push_back(build10);
    mUILabelProperties.push_back(build11);
    mUILabelProperties.push_back(build12);
    mUILabelProperties.push_back(build13);
    mUILabelProperties.push_back(build14);
    mUILabelProperties.push_back(build15);
    mUILabelProperties.push_back(build16);
}
