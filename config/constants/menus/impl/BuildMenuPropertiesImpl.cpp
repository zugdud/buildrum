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
    setUIButtonStateProperties();
}

const UIMenuProperties & BuildMenuPropertiesImpl::getUIMenuProperties() const
{
    return mUIMenuProperties;
}
const std::vector<UIButtonProperties> & BuildMenuPropertiesImpl::getUIButtonProperties()
{
    return mUIButtonProperties;
}
const std::vector<UIButtonStateProperties> & BuildMenuPropertiesImpl::getUIButtonStateProperties()
{
    return mUIButtonStateProperties;
}
const std::vector<UILabelProperties> & BuildMenuPropertiesImpl::getUILabelProperties()
{
    return mUILabelProperties;
}

void BuildMenuPropertiesImpl::setUIMenuProperties()
{
    SDL_Color blue = { 0, 0, 255, 255 };
    SDL_Color green = { 0, 255, 0, 255 };

    // UIRenderCellDetails: backgroundColor, outlineColor, showBorderColor, showBackgroundColor, backgroundSpriteId, showbackgroundSprite
    UIRenderCellDetails gridCD = { blue, green, true, true, 0, false };

    UIMenuProperties uiMenuProperties;

    uiMenuProperties.uiMenuId = "BuildMenu";
    uiMenuProperties.viewportId = "gameView";
    uiMenuProperties.rows = 4;
    uiMenuProperties.columns = 4;
    uiMenuProperties.xPadding = 50;
    uiMenuProperties.yPadding = 50;
    uiMenuProperties.uiRenderCellDetails = gridCD;
    uiMenuProperties.hidden = true;

    mUIMenuProperties = uiMenuProperties;
}

void BuildMenuPropertiesImpl::setButtonProperties()
{
    // orderId, buttonId, xPadding, yPadding, actionId, defaultButtonState, isSpacer

    UIButtonProperties build1 = { 0, "build1", 20, 20, "build1", "buttonAvailable", false };
    UIButtonProperties build2 = { 1, "build2", 20, 20, "build2", "buttonAvailable", false };
    UIButtonProperties build3 = { 2, "build3", 20, 20, "build3", "buttonAvailable", false };
    UIButtonProperties build4 = { 3, "build4", 20, 20, "build4", "buttonAvailable", false };
    UIButtonProperties build5 = { 4, "build5", 20, 20, "build5", "buttonAvailable", false };
    UIButtonProperties build6 = { 5, "build6", 20, 20, "build6", "buttonAvailable", false };
    UIButtonProperties build7 = { 6, "build7", 20, 20, "build7", "buttonAvailable", false };
    UIButtonProperties build8 = { 7, "build8", 20, 20, "build8", "buttonAvailable", false };
    UIButtonProperties build9 = { 8, "build9", 20, 20, "build9", "buttonAvailable", false };
    UIButtonProperties build10 = { 9, "build10", 20, 20, "build10", "buttonAvailable", false };
    UIButtonProperties build11 = { 10, "build11", 20, 20, "build11", "buttonAvailable", false };
    UIButtonProperties build12 = { 11, "build12", 20, 20, "build12", "buttonAvailable", false };
    UIButtonProperties build13 = { 12, "build13", 20, 20, "build13", "buttonAvailable", false };
    UIButtonProperties build14 = { 13, "build14", 20, 20, "build14", "buttonAvailable", false };
    UIButtonProperties build15 = { 14, "build15", 20, 20, "build15", "buttonAvailable", false };
    UIButtonProperties build16 = { 15, "build16", 20, 20, "build16", "buttonAvailable", false };

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

void BuildMenuPropertiesImpl::setUIButtonStateProperties()
{
    SDL_Color black = { 0, 0, 0, 255 };
    SDL_Color red = { 255, 0, 0, 255 };
    SDL_Color green = { 0, 255, 0, 255 };

    // UIRenderCellDetails: isSpacer, backgroundColor, outlineColor, showBorderColor, showBackgroundColor, backgroundSpriteId, showbackgroundSprite
    // UIButtonStateProperties: buttonState, spriteId, soundEffectId, uiRenderCellDetails
    UIRenderCellDetails buttonSelectedCD = {  green, red, true, true, 0, false  };
    UIButtonStateProperties buttonSelected = { "buttonSelected", 0, "buttonSelected", buttonSelectedCD };

    UIRenderCellDetails buttonAvailableCD = {  black, red, true, true, 0, false  };
    UIButtonStateProperties buttonAvailable = { "buttonAvailable", 1, "", buttonAvailableCD };

    UIRenderCellDetails buttonCooldownCD = {  black, red, true, true, 0, false  };
    UIButtonStateProperties buttonCooldown = { "buttonCooldown", 2, "", buttonCooldownCD };

    UIRenderCellDetails buttonUnavailableCD = { black, red, true, true, 0, false  };
    UIButtonStateProperties buttonUnavailable = { "buttonUnavailable", 3, "", buttonUnavailableCD };

    mUIButtonStateProperties.push_back(buttonSelected);
    mUIButtonStateProperties.push_back(buttonAvailable);
    mUIButtonStateProperties.push_back(buttonCooldown);
    mUIButtonStateProperties.push_back(buttonUnavailable);
}

void BuildMenuPropertiesImpl::setUILabelProperties()
{
    // orderId, labelText, fontId, xPadding, yPadding, isSpacer. alignment
    UILabelProperties build1 = { 0, "Build 1", "Heading_3_OpenSansLight", 10, 10, false, "center" };
    UILabelProperties build2 = { 0, "Build 2", "Heading_3_OpenSansLight", 10, 10, false, "center" };
    UILabelProperties build3 = { 0, "Build 3", "Heading_3_OpenSansLight", 10, 10, false, "center" };
    UILabelProperties build4 = { 0, "Build 4", "Heading_3_OpenSansLight", 10, 10, false, "center" };
    UILabelProperties build5 = { 0, "Build 5", "Heading_3_OpenSansLight", 10, 10, false, "center" };
    UILabelProperties build6 = { 0, "Build 6", "Heading_3_OpenSansLight", 10, 10, false, "center" };
    UILabelProperties build7 = { 0, "Build 7", "Heading_3_OpenSansLight", 10, 10, false, "center" };
    UILabelProperties build8 = { 0, "Build 8", "Heading_3_OpenSansLight", 10, 10, false, "center" };
    UILabelProperties build9 = { 0, "Build 9", "Heading_3_OpenSansLight", 10, 10, false, "center" };
    UILabelProperties build10 = { 0, "Build 10", "Heading_3_OpenSansLight", 10, 10, false, "center" };
    UILabelProperties build11 = { 0, "Build 11", "Heading_3_OpenSansLight", 10, 10, false, "center" };
    UILabelProperties build12 = { 0, "Build 12", "Heading_3_OpenSansLight", 10, 10, false, "center" };
    UILabelProperties build13 = { 0, "Build 13", "Heading_3_OpenSansLight", 10, 10, false, "center" };
    UILabelProperties build14 = { 0, "Build 14", "Heading_3_OpenSansLight", 10, 10, false, "center" };
    UILabelProperties build15 = { 0, "Build 15", "Heading_3_OpenSansLight", 10, 10, false, "center" };
    UILabelProperties build16 = { 0, "Build 16", "Heading_3_OpenSansLight", 10, 10, false, "center" };

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