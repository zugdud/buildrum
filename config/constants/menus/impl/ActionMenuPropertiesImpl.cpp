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
    uiMenuProperties.columns = 4;
    uiMenuProperties.xPadding = 20;
    uiMenuProperties.yPadding = 20;
    uiMenuProperties.uiRenderCellDetails = gridCD;

    mUIMenuProperties = uiMenuProperties;
}

void ActionMenuPropertiesImpl::setButtonProperties()
{
    // orderId, buttonId, xPadding, yPadding, actionId, defaultButtonState, isSpacer
    UIButtonProperties spacer = { 0, "spacer", 20, 20, "spacer", "buttonAvailable", true };
    UIButtonProperties newGame = { 1, "newGame", 20, 20, "newGame",  "buttonAvailable", false };
    UIButtonProperties resumeGame = { 2, "resumeGame", 20, 20, "resumeGame",  "buttonAvailable", false };
    UIButtonProperties quitGame = { 3, "quitGame", 20, 20, "quitGame",  "buttonAvailable", false };

    mUIButtonProperties.push_back(spacer);
    mUIButtonProperties.push_back(newGame);
    mUIButtonProperties.push_back(resumeGame);
    mUIButtonProperties.push_back(quitGame);
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
    UILabelProperties mainMenuLabel = { 0, "Main Menu", "Heading_1_OpenSansLight", 10, 10, false, "center" };
    UILabelProperties newGame = { 1, "New Game", "Heading_1_OpenSansLight", 20, 20, false, "left" };
    UILabelProperties resumeGame = { 2, "Resume Game", "Heading_1_OpenSansLight", 20, 20, false, "left" };
    UILabelProperties quitGame = { 3, "Quit Game", "Heading_1_OpenSansLight", 20, 20, false, "left" };

    mUILabelProperties.push_back(mainMenuLabel);
    mUILabelProperties.push_back(newGame);
    mUILabelProperties.push_back(resumeGame);
    mUILabelProperties.push_back(quitGame);
}
