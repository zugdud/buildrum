#include "include/global.hpp"

ActionMenuPropertiesImpl::ActionMenuPropertiesImpl()
{

}

ActionMenuPropertiesImpl::~ActionMenuPropertiesImpl()
{

}

void ActionMenuPropertiesImpl::setProperties()
{
    SDL_Log("ActionMenuPropertiesImpl::loadAll -- loading configuration ...\n");
    setUIMenuProperties();
    setButtonProperties();
    setUILabelProperties();
    setUIButtonStateProperties();
}

const UIMenuProperties & ActionMenuPropertiesImpl::getUIMenuProperties() const
{
    return mUIMenuProperties;
}
const std::vector<UIButtonProperties> & ActionMenuPropertiesImpl::getUIButtonProperties()
{
    return mUIButtonProperties;
}
const std::vector<UIButtonStateProperties> & ActionMenuPropertiesImpl::getUIButtonStateProperties()
{
    return mUIButtonStateProperties;
}
const std::vector<UILabelProperties> & ActionMenuPropertiesImpl::getUILabelProperties()
{
    return mUILabelProperties;
}

void ActionMenuPropertiesImpl::setUIMenuProperties()
{
    SDL_Color blue = { 0, 0, 255, 255 };
    SDL_Color green = { 0, 255, 0, 255 };

    // UIRenderCellDetails: backgroundColor, outlineColor, showBorderColor, showBackgroundColor, backgroundSpriteId, showbackgroundSprite
    UIRenderCellDetails gridCD = { blue, green, true, true, 0, false };

    UIMenuProperties uiMenuProperties;

    uiMenuProperties.uiMenuId = "ActionMenu";
    uiMenuProperties.viewportId = "actionMenu";
    uiMenuProperties.rows = 1;
    uiMenuProperties.columns = 2;
    uiMenuProperties.xPadding = 0;
    uiMenuProperties.yPadding = 0;
    uiMenuProperties.uiRenderCellDetails = gridCD;

    mUIMenuProperties = uiMenuProperties;
}

void ActionMenuPropertiesImpl::setButtonProperties()
{
    // orderId, buttonId, xPadding, yPadding, actionId, defaultButtonState, isSpacer
    UIButtonProperties quitGame = { 1, "quitGame", 20, 20, "quitGame",  "buttonAvailable", false };
    UIButtonProperties buildMenu = { 2, "buildMenu", 20, 20, "buildMenu",  "buttonAvailable", false };

    mUIButtonProperties.push_back(quitGame);
    mUIButtonProperties.push_back(buildMenu);
}

void ActionMenuPropertiesImpl::setUIButtonStateProperties()
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

void ActionMenuPropertiesImpl::setUILabelProperties()
{
    // orderId, labelText, fontId, xPadding, yPadding, isSpacer. alignment
    UILabelProperties quitGame = { 0, "Quit Game", "Heading_1_OpenSansLight", 10, 10, false, "center" };
    UILabelProperties buildMenu = { 1, "Build Menu", "Heading_1_OpenSansLight", 20, 20, false, "center" };

    mUILabelProperties.push_back(quitGame);
    mUILabelProperties.push_back(buildMenu);
}
