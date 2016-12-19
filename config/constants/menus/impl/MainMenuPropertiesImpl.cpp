#include "include/global.hpp"

MainMenuPropertiesImpl::MainMenuPropertiesImpl()
{

}

MainMenuPropertiesImpl::~MainMenuPropertiesImpl()
{

}

void MainMenuPropertiesImpl::setProperties()
{
    SDL_Log("MainMenuPropertiesImpl::loadAll -- loading configuration ...\n");
    setUIMenuProperties();
    setButtonProperties();
    setUILabelProperties();
    setUIButtonStateProperties();
}

const UIMenuProperties & MainMenuPropertiesImpl::getUIMenuProperties() const
{
    return mUIMenuProperties;
}
const std::vector<UIButtonProperties> & MainMenuPropertiesImpl::getUIButtonProperties()
{
    return mUIButtonProperties;
}
const std::vector<UIButtonStateProperties> & MainMenuPropertiesImpl::getUIButtonStateProperties()
{
    return mUIButtonStateProperties;
}
const std::vector<UILabelProperties> & MainMenuPropertiesImpl::getUILabelProperties()
{
    return mUILabelProperties;
}

void MainMenuPropertiesImpl::setUIMenuProperties()
{
    SDL_Color blue = { 0, 0, 255, 255 };
    SDL_Color green = { 0, 255, 0, 255 };

    // UIRenderCellDetails: backgroundColor, outlineColor, showBorderColor, showBackgroundColor, backgroundSpriteId, showbackgroundSprite
    UIRenderCellDetails gridCD = { blue, green, true, true, 0, false };

    UIMenuProperties uiMenuProperties;

    uiMenuProperties.uiMenuId = "MainMenu";
    uiMenuProperties.viewportId = "fullscreen";
    uiMenuProperties.rows = 4;
    uiMenuProperties.columns = 1;
    uiMenuProperties.xPadding = 50;
    uiMenuProperties.yPadding = 50;
    uiMenuProperties.uiRenderCellDetails = gridCD;

    mUIMenuProperties = uiMenuProperties;
}

void MainMenuPropertiesImpl::setButtonProperties()
{
    // orderId, buttonId, xPadding, yPadding, actionId, defaultButtonState, isSpacer
    UIButtonProperties spacer = { 0, "spacer", 20, 20, "spacer", "buttonAvailable", true };
    UIButtonProperties newGame = { 1, "newGame", 20, 20, "newGame",  "buttonAvailable", false };
    UIButtonProperties resumeGame = { 2, "resumeGame", 20, 20, "resumeGame",  "buttonAvailable", false };
    UIButtonProperties exitGame = { 3, "exitGame", 20, 20, "exitGame",  "buttonAvailable", false };

    mUIButtonProperties.push_back(spacer);
    mUIButtonProperties.push_back(newGame);
    mUIButtonProperties.push_back(resumeGame);
    mUIButtonProperties.push_back(exitGame);
}

void MainMenuPropertiesImpl::setUIButtonStateProperties()
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

void MainMenuPropertiesImpl::setUILabelProperties()
{
    // orderId, labelText, fontId, xPadding, yPadding, isSpacer. alignment
    UILabelProperties mainMenuLabel = { 0, "Main Menu", "Heading_1_OpenSansLight", 10, 10, false, "center" };
    UILabelProperties newGame = { 1, "New Game", "Heading_1_OpenSansLight", 20, 20, false, "left" };
    UILabelProperties resumeGame = { 2, "Resume Game", "Heading_1_OpenSansLight", 20, 20, false, "left" };
    UILabelProperties exitGame = { 3, "Exit Game", "Heading_1_OpenSansLight", 20, 20, false, "left" };

    mUILabelProperties.push_back(mainMenuLabel);
    mUILabelProperties.push_back(newGame);
    mUILabelProperties.push_back(resumeGame);
    mUILabelProperties.push_back(exitGame);
}
