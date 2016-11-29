#include "include/global.hpp"

MainMenuProperties::MainMenuProperties()
{
    setUIMenuProperties();
    setButtonProperties();
    setUILabelProperties();
    setUIButtonStateProperties();
}

MainMenuProperties::~MainMenuProperties()
{

}

void MainMenuProperties::setUIMenuProperties()
{
    RGBAColors blue = { 0, 0, 255, 255 };
    RGBAColors green = { 0, 255, 0, 255 };

    mUIMenuProperties.uiMenuId = "MainMenu";
    mUIMenuProperties.viewportId = "fullscreen";
    mUIMenuProperties.rows = 4;
    mUIMenuProperties.columns = 1;
    mUIMenuProperties.xPadding = 50;
    mUIMenuProperties.yPadding = 50;
    mUIMenuProperties.bgColor = blue;
    mUIMenuProperties.gridLineColor = green;
    mUIMenuProperties.drawBorder = true;
}



void MainMenuProperties::setButtonProperties()
{
    // orderId, buttonId, xPadding, yPadding, actionId
    UIButtonProperties newGame = { 0, "newGame", 20, 20, "newGame" };
    UIButtonProperties resumeGame = { 1, "resumeGame", 20, 20, "resumeGame" };
    UIButtonProperties quitGame = { 2, "quitGame", 20, 20, "quitGame" };

    mUIButtonProperties.push_back(newGame);
    mUIButtonProperties.push_back(resumeGame);
    mUIButtonProperties.push_back(quitGame);
}

void MainMenuProperties::setUILabelProperties()
{
    // orderId, labelText, fontId, xPadding, yPadding
    UILabelProperties newGame = { 0, "Main Menu", "OpenSans-Bold", 10, 10 };
    UILabelProperties newGame = { 1, "New Game", "OpenSans-Light", 20, 20 };
    UILabelProperties resumeGame = { 2, "Resume Game", "OpenSans-Light", 20, 20 };
    UILabelProperties quitGame = { 3, "Quit Game", "OpenSans-Light", 20, 20 };

    mUILabelProperties.push_back(newGame);
    mUILabelProperties.push_back(resumeGame);
    mUILabelProperties.push_back(quitGame);
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

    mUIButtonStateProperties.push_back(buttonSelected);
    mUIButtonStateProperties.push_back(buttonAvailable);
    mUIButtonStateProperties.push_back(buttonCooldown);
    mUIButtonStateProperties.push_back(buttonUnavailable);
};
