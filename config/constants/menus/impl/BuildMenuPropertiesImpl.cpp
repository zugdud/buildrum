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

    std::vector<std::string> spriteNames;
    setSpriteNames(spriteNames);
    setButtonProperties(spriteNames);
    setUILabelProperties(spriteNames);
}

void BuildMenuPropertiesImpl::setSpriteNames(std::vector<std::string> & spriteNames)
{
    spriteNames.push_back("banner_1");
    spriteNames.push_back("banner_2");
    spriteNames.push_back("emblem_2");
    spriteNames.push_back("spire_1");
    spriteNames.push_back("ladder_1");
    spriteNames.push_back("anvil_1");
    spriteNames.push_back("anvil_2");
    spriteNames.push_back("latern_1");
    spriteNames.push_back("latern_1");
    spriteNames.push_back("crate_1");
    spriteNames.push_back("crate_2");
    spriteNames.push_back("crate_3");
    spriteNames.push_back("crate_4");
    spriteNames.push_back("crate_5");
    spriteNames.push_back("barrel_1");
    spriteNames.push_back("barrel_1");
}

void BuildMenuPropertiesImpl::setUIMenuProperties()
{
    SDL_Color blue = { 0, 0, 255, 255 };
    SDL_Color green = { 0, 255, 0, 255 };

    // UIRenderCellDetails: backgroundColor, outlineColor, showBorderColor, showBackgroundColor, backgroundSpriteId, showbackgroundSprite
    UIRenderCellDetails gridCD = { blue, green, true, true, "brick_2", false };

    UIMenuProperties uiMenuProperties;

    uiMenuProperties.uiMenuId = "BuildMenu";
    uiMenuProperties.viewportId = "gameView";
    uiMenuProperties.rows = 4;
    uiMenuProperties.columns = 4;
    uiMenuProperties.xPadding = 20;
    uiMenuProperties.yPadding = 20;
    uiMenuProperties.uiRenderCellDetails = gridCD;
    uiMenuProperties.hidden = true;

    mUIMenuProperties = uiMenuProperties;
}

void BuildMenuPropertiesImpl::setButtonProperties(std::vector<std::string> & spriteNames)
{
    for (size_t i = 0; i < spriteNames.size(); i++)
    {
        const std::string eventId = "build_" + spriteNames[i];
        UIButtonProperties uiButtonProperties = { i, eventId, 20, 20, eventId, "buttonAvailable", false };
        mUIButtonProperties.push_back(uiButtonProperties);
        BaseMenuProperties::setUIButtonStateProperties(eventId, spriteNames[i], true);
    }
}

void BuildMenuPropertiesImpl::setUILabelProperties(std::vector<std::string> & spriteNames)
{
    for (size_t i = 0; i < spriteNames.size(); i++)
    {
        UILabelProperties uiLabelProperties = { i, spriteNames[i], "Heading_3_OpenSansLight", 10, 10, false, "center" };
        mUILabelProperties.push_back(uiLabelProperties);
    }
}
