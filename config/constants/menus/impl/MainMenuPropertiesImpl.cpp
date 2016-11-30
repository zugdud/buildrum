#include "include/global.hpp"

MainMenuPropertiesImpl::MainMenuPropertiesImpl()
{

}

MainMenuPropertiesImpl::~MainMenuPropertiesImpl()
{

}

void MainMenuPropertiesImpl::setProperties(MenuPropertiesContainer & menuPropertiesContainer)
{
    setUIMenuProperties(menuPropertiesContainer);
    setButtonProperties(menuPropertiesContainer);
    setUILabelProperties(menuPropertiesContainer);
    setUIButtonStateProperties(menuPropertiesContainer);
}

void MainMenuPropertiesImpl::setUIMenuProperties(MenuPropertiesContainer & menuPropertiesContainer)
{
    RGBAColors blue = { 0, 0, 255, 255 };
    RGBAColors green = { 0, 255, 0, 255 };

    // UIRenderCellDetails: isSpacer, backgroundColor, outlineColor, showBorderColor, showBackgroundColor, backgroundSpriteId, showbackgroundSprite
    UIRenderCellDetails gridCD = { false, blue, green, true, true, 0, false  };

    UIMenuProperties uiMenuProperties;

    uiMenuProperties.uiMenuId = "MainMenu";
    uiMenuProperties.viewportId = "fullscreen";
    uiMenuProperties.rows = 4;
    uiMenuProperties.columns = 1;
    uiMenuProperties.xPadding = 50;
    uiMenuProperties.yPadding = 50;
    uiMenuProperties.uiRenderCellDetails = gridCD;

    menuPropertiesContainer.setUIMenuProperties(uiMenuProperties);
}

void MainMenuPropertiesImpl::setButtonProperties(MenuPropertiesContainer & menuPropertiesContainer)
{
    // orderId, buttonId, xPadding, yPadding, actionId, defaultButtonState
    UIButtonProperties spacer = { 0, "spacer", 20, 20, "spacer", true, "buttonAvailable" };
    UIButtonProperties newGame = { 1, "newGame", 20, 20, "newGame", false, "buttonAvailable" };
    UIButtonProperties resumeGame = { 2, "resumeGame", 20, 20, "resumeGame", false, "buttonAvailable" };
    UIButtonProperties quitGame = { 3, "quitGame", 20, 20, "quitGame", false, "buttonAvailable" };

    menuPropertiesContainer.addUIButtonProperties(spacer);
    menuPropertiesContainer.addUIButtonProperties(newGame);
    menuPropertiesContainer.addUIButtonProperties(resumeGame);
    menuPropertiesContainer.addUIButtonProperties(quitGame);
}

void MainMenuPropertiesImpl::setUIButtonStateProperties(MenuPropertiesContainer & menuPropertiesContainer)
{
    RGBAColors black = { 0, 0, 0, 255 };
    RGBAColors red = { 255, 0, 0, 255 };
    RGBAColors green = { 0, 255, 0, 255 };

    // UIRenderCellDetails: isSpacer, backgroundColor, outlineColor, showBorderColor, showBackgroundColor, backgroundSpriteId, showbackgroundSprite
    // UIButtonStateProperties: buttonState, spriteId, soundEffectId, uiRenderCellDetails
    UIRenderCellDetails buttonSelectedCD = { false, green, red, true, true, 0, false  };
    UIButtonStateProperties buttonSelected = { "buttonSelected", 0, "buttonSelected", buttonSelectedCD };

    UIRenderCellDetails buttonAvailableCD = { false, black, red, true, true, 0, false  };
    UIButtonStateProperties buttonAvailable = { "buttonAvailable", 1, "", buttonAvailableCD };

    UIRenderCellDetails buttonCooldownCD = { false, black, red, true, true, 0, false  };
    UIButtonStateProperties buttonCooldown = { "buttonCooldown", 2, "", buttonCooldownCD };

    UIRenderCellDetails buttonUnavailableCD = { false, black, red, true, true, 0, false  };
    UIButtonStateProperties buttonUnavailable = { "buttonUnavailable", 3, "", buttonUnavailableCD };

    menuPropertiesContainer.addUIButtonStateProperties(buttonSelected);
    menuPropertiesContainer.addUIButtonStateProperties(buttonAvailable);
    menuPropertiesContainer.addUIButtonStateProperties(buttonCooldown);
    menuPropertiesContainer.addUIButtonStateProperties(buttonUnavailable);
}

void MainMenuPropertiesImpl::setUILabelProperties(MenuPropertiesContainer & menuPropertiesContainer)
{
    // orderId, labelText, fontId, xPadding, yPadding, isSpacer
    UILabelProperties mainMenuLabel = { 0, "Main Menu", "OpenSans-Bold", 10, 10, false };
    UILabelProperties newGame = { 1, "New Game", "OpenSans-Light", 20, 20, false };
    UILabelProperties resumeGame = { 2, "Resume Game", "OpenSans-Light", 20, 20, false };
    UILabelProperties quitGame = { 3, "Quit Game", "OpenSans-Light", 20, 20, false };

    menuPropertiesContainer.addUILabelProperties(mainMenuLabel);
    menuPropertiesContainer.addUILabelProperties(newGame);
    menuPropertiesContainer.addUILabelProperties(resumeGame);
    menuPropertiesContainer.addUILabelProperties(quitGame);
}
