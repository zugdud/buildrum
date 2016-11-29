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
    mUIMenuProperties.uiMenuId = "MainMenu";
    mUIMenuProperties.viewportId = "fullscreen";
    mUIMenuProperties.rows = 4;
    mUIMenuProperties.columns = 1;
    mUIMenuProperties.xPadding = 50;
    mUIMenuProperties.yPadding = 50;
}

void MainMenuProperties::setButtonProperties()
{
    // orderId, buttonId, xPadding, yPadding, actionId;
    UIButtonProperties newGame = { 0, "newGame", 20, 20, "newGame" };
    UIButtonProperties resumeGame = { 1, "resumeGame", 20, 20, "resumeGame" };
    UIButtonProperties quitGame = { 2, "quitGame", 20, 20, "quitGame" };

    mUIButtonProperties.push_back(newGame);
    mUIButtonProperties.push_back(resumeGame);
    mUIButtonProperties.push_back(quitGame);
}

void MainMenuProperties::setUILabelProperties()
{
    // orderId, labelText, fontId
    UILabelProperties newGame = { 0, "New Game", "OpenSans-Light" };
    UILabelProperties resumeGame = { 0, "Resume Game", "OpenSans-Light" };
    UILabelProperties quitGame = { 0, "Quit Game", "OpenSans-Light" };

    mUILabelProperties.push_back(newGame);
    mUILabelProperties.push_back(resumeGame);
    mUILabelProperties.push_back(quitGame);
}

void MainMenuProperties::setUIButtonStateProperties()
{
    // buttonState, spriteId, soundEffectId
    UIButtonProperties buttonSelected = { "buttonSelected", 0, "buttonSelected" };
    UIButtonProperties buttonAvailable = { "buttonAvailable", 1, "" };
    UIButtonProperties buttonCooldown = { "buttonCooldown", 2, "" };
    UIButtonProperties buttonUnavailable = { "buttonUnavailable", 3, "" };

    mUIButtonStateProperties.push_back(buttonSelected);
    mUIButtonStateProperties.push_back(buttonAvailable);
    mUIButtonStateProperties.push_back(buttonCooldown);
    mUIButtonStateProperties.push_back(buttonUnavailable);
};
