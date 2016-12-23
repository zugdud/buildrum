#include "include/global.hpp"

SelectedActionMenuPropertiesImpl::SelectedActionMenuPropertiesImpl()
{

}

SelectedActionMenuPropertiesImpl::~SelectedActionMenuPropertiesImpl()
{

}

void SelectedActionMenuPropertiesImpl::setProperties()
{
    SDL_Log("SelectedActionMenuPropertiesImpl::loadAll -- loading configuration ...\n");
    setUIMenuProperties();
    setButtonProperties();
    setUILabelProperties();
}

void SelectedActionMenuPropertiesImpl::setUIMenuProperties()
{
    SDL_Color blue = { 0, 0, 255, 255 };
    SDL_Color green = { 0, 255, 0, 255 };

    SpriteProperties spriteProperties = { 195, "castle_1", SDL_FLIP_NONE, 0 };
    // UIRenderCellDetails: backgroundColor, outlineColor, showBorderColor, showBackgroundColor, backgroundSpriteId, showbackgroundSprite
    UIRenderCellDetails gridCD = { blue, green, true, true, spriteProperties, false };

    UIMenuProperties uiMenuProperties;

    uiMenuProperties.uiMenuId = "SelectedActionMenu";
    uiMenuProperties.viewportId = "selectedAction";
    uiMenuProperties.rows = 1;
    uiMenuProperties.columns = 1;
    uiMenuProperties.xPadding = 0;
    uiMenuProperties.yPadding = 0;
    uiMenuProperties.uiRenderCellDetails = gridCD;
    uiMenuProperties.hidden = false;

    mUIMenuProperties = uiMenuProperties;
}

void SelectedActionMenuPropertiesImpl::setButtonProperties()
{
    // orderId, buttonId, xPadding, yPadding, actionId, defaultButtonState, isSpacer
    UIButtonProperties selectedAction = { 1, "selectedAction", 20, 20, "selectedAction",  "buttonAvailable", true };

    BaseMenuProperties::setUIButtonStateProperties("selectedAction", 195, "castle_1", true);

    mUIButtonProperties.push_back(selectedAction);
}

void SelectedActionMenuPropertiesImpl::setUILabelProperties()
{
    // orderId, labelText, fontId, xPadding, yPadding, isSpacer. alignment
    UILabelProperties selectedAction = { 0, "Selected Action", "Heading_1_OpenSansLight", 10, 10, false, "center" };

    mUILabelProperties.push_back(selectedAction);
}
