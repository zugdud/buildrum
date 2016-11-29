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

    UIMenuProperties uiMenuProperties;

    uiMenuProperties.uiMenuId = "MainMenu";
    uiMenuProperties.viewportId = "fullscreen";
    uiMenuProperties.rows = 4;
    uiMenuProperties.columns = 1;
    uiMenuProperties.xPadding = 50;
    uiMenuProperties.yPadding = 50;
    uiMenuProperties.bgColor = blue;
    uiMenuProperties.gridLineColor = green;
    uiMenuProperties.drawBorder = true;

    menuPropertiesContainer.setUIMenuProperties(uiMenuProperties);
}

void MainMenuPropertiesImpl::setButtonProperties(MenuPropertiesContainer & menuPropertiesContainer)
{
    // orderId, buttonId, xPadding, yPadding, actionId
    UIButtonProperties newGame = { 0, "newGame", 20, 20, "newGame" };
    UIButtonProperties resumeGame = { 1, "resumeGame", 20, 20, "resumeGame" };
    UIButtonProperties quitGame = { 2, "quitGame", 20, 20, "quitGame" };

    menuPropertiesContainer.addUIButtonProperties(newGame);
    menuPropertiesContainer.addUIButtonProperties(resumeGame);
    menuPropertiesContainer.addUIButtonProperties(quitGame);
}

void MainMenuPropertiesImpl::setUILabelProperties(MenuPropertiesContainer & menuPropertiesContainer)
{
    // orderId, labelText, fontId, xPadding, yPadding
    UILabelProperties mainMenuLabel = { 0, "Main Menu", "OpenSans-Bold", 10, 10 };
    UILabelProperties newGame = { 1, "New Game", "OpenSans-Light", 20, 20 };
    UILabelProperties resumeGame = { 2, "Resume Game", "OpenSans-Light", 20, 20 };
    UILabelProperties quitGame = { 3, "Quit Game", "OpenSans-Light", 20, 20 };

    menuPropertiesContainer.addUILabelProperties(mainMenuLabel);
    menuPropertiesContainer.addUILabelProperties(newGame);
    menuPropertiesContainer.addUILabelProperties(resumeGame);
    menuPropertiesContainer.addUILabelProperties(quitGame);
}

void MainMenuPropertiesImpl::setUIButtonStateProperties(MenuPropertiesContainer & menuPropertiesContainer)
{
    RGBAColors black = { 0, 0, 0, 255 };
    RGBAColors red = { 255, 0, 0, 255 };

    // buttonState, spriteId, soundEffectId, bgColor, borderColor, drawBorder
    UIButtonStateProperties buttonSelected = { "buttonSelected", 0, "buttonSelected", black, red, true };
    UIButtonStateProperties buttonAvailable = { "buttonAvailable", 1, "", black, red, true };
    UIButtonStateProperties buttonCooldown = { "buttonCooldown", 2, "", black, red, true };
    UIButtonStateProperties buttonUnavailable = { "buttonUnavailable", 3, "", black, red, true };

    menuPropertiesContainer.addUIButtonStateProperties(buttonSelected);
    menuPropertiesContainer.addUIButtonStateProperties(buttonAvailable);
    menuPropertiesContainer.addUIButtonStateProperties(buttonCooldown);
    menuPropertiesContainer.addUIButtonStateProperties(buttonUnavailable);
};
