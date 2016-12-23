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
}

void MainMenuPropertiesImpl::setUIMenuProperties()
{
    SDL_Color blue = { 0, 0, 255, 255 };
    SDL_Color green = { 0, 255, 0, 255 };

    SpriteProperties spriteProperties = { 195, "castle_1", SDL_FLIP_NONE, 0 };
    // UIRenderCellDetails: backgroundColor, outlineColor, showBorderColor, showBackgroundColor, backgroundSpriteId, showbackgroundSprite
    UIRenderCellDetails gridCD = { blue, green, true, true, spriteProperties, false };

    UIMenuProperties uiMenuProperties;

    uiMenuProperties.uiMenuId = "MainMenu";
    uiMenuProperties.viewportId = "fullscreen";
    uiMenuProperties.rows = 4;
    uiMenuProperties.columns = 1;
    uiMenuProperties.xPadding = 50;
    uiMenuProperties.yPadding = 50;
    uiMenuProperties.uiRenderCellDetails = gridCD;
    uiMenuProperties.hidden = false;

    mUIMenuProperties = uiMenuProperties;
}

void MainMenuPropertiesImpl::setButtonProperties()
{
    // orderId, buttonId, xPadding, yPadding, actionId, defaultButtonState, isSpacer
    UIButtonProperties spacer = { 0, "spacer", 20, 20, "spacer", "buttonAvailable", true };
    UIButtonProperties newGame = { 1, "newGame", 20, 20, "newGame",  "buttonAvailable", false };
    UIButtonProperties resumeGame = { 2, "resumeGame", 20, 20, "resumeGame",  "buttonAvailable", false };
    UIButtonProperties exitGame = { 3, "exitGame", 20, 20, "exitGame",  "buttonAvailable", false };

    const int defaultSpriteId = 195;
    const std::string defaultSpriteSheetId = "castle_1";

    BaseMenuProperties::setUIButtonStateProperties("spacer", defaultSpriteId, defaultSpriteSheetId, false);
    BaseMenuProperties::setUIButtonStateProperties("newGame", defaultSpriteId, defaultSpriteSheetId, false);
    BaseMenuProperties::setUIButtonStateProperties("resumeGame", defaultSpriteId, defaultSpriteSheetId, false);
    BaseMenuProperties::setUIButtonStateProperties("exitGame", defaultSpriteId, defaultSpriteSheetId, false);

    mUIButtonProperties.push_back(spacer);
    mUIButtonProperties.push_back(newGame);
    mUIButtonProperties.push_back(resumeGame);
    mUIButtonProperties.push_back(exitGame);

    // generate properties

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
