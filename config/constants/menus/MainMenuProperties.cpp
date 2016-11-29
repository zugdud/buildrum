#include "include/global.hpp"

MainMenuProperties::MainMenuProperties()
{
    setUIMenuProperties();
    setButtonProperties();
    setUILabelProperties();
    setUIButtonStateProperties();

    mMenuProperties = *new MenuProperties();
}

MainMenuProperties::~MainMenuProperties()
{

}

void MainMenuProperties::setUIMenuProperties()
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

    mMenuProperties.setUIMenuProperties(uiMenuProperties);
}

void MainMenuProperties::setButtonProperties()
{
    // orderId, buttonId, xPadding, yPadding, actionId
    UIButtonProperties newGame = { 0, "newGame", 20, 20, "newGame" };
    UIButtonProperties resumeGame = { 1, "resumeGame", 20, 20, "resumeGame" };
    UIButtonProperties quitGame = { 2, "quitGame", 20, 20, "quitGame" };

    mMenuProperties.addUIButtonProperties(newGame);
    mMenuProperties.addUIButtonProperties(resumeGame);
    mMenuProperties.addUIButtonProperties(quitGame);
}

void MainMenuProperties::setUILabelProperties()
{
    // orderId, labelText, fontId, xPadding, yPadding
    UILabelProperties mainMenuLabel = { 0, "Main Menu", "OpenSans-Bold", 10, 10 };
    UILabelProperties newGame = { 1, "New Game", "OpenSans-Light", 20, 20 };
    UILabelProperties resumeGame = { 2, "Resume Game", "OpenSans-Light", 20, 20 };
    UILabelProperties quitGame = { 3, "Quit Game", "OpenSans-Light", 20, 20 };

    mMenuProperties.addUILabelProperties(mainMenuLabel);
    mMenuProperties.addUILabelProperties(newGame);
    mMenuProperties.addUILabelProperties(resumeGame);
    mMenuProperties.addUILabelProperties(quitGame);
}

void MainMenuProperties::setUIButtonStateProperties()
{
    RGBAColors black = { 0, 0, 0, 255 };
    RGBAColors red = { 255, 0, 0, 255 };

    // buttonState, spriteId, soundEffectId, bgColor, borderColor, drawBorder
    UIButtonProperties buttonSelected = { "buttonSelected", 0, "buttonSelected", black, red, true };
    UIButtonProperties buttonAvailable = { "buttonAvailable", 1, "", black, red, true };
    UIButtonProperties buttonCooldown = { "buttonCooldown", 2, "", black, red, true };
    UIButtonProperties buttonUnavailable = { "buttonUnavailable", 3, "", black, red, true };

    mMenuProperties.addUIButtonStateProperties(buttonSelected);
    mMenuProperties.addUIButtonStateProperties(buttonAvailable);
    mMenuProperties.addUIButtonStateProperties(buttonCooldown);
    mMenuProperties.addUIButtonStateProperties(buttonUnavailable);
};
