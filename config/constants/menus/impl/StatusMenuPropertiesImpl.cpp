#include "include/global.hpp"

StatusMenuPropertiesImpl::StatusMenuPropertiesImpl()
{

}

StatusMenuPropertiesImpl::~StatusMenuPropertiesImpl()
{

}

void StatusMenuPropertiesImpl::setProperties()
{
    SDL_Log("StatusMenuPropertiesImpl::loadAll -- loading configuration ...\n");
    setUIMenuProperties();
    setButtonProperties();
    setUILabelProperties();
}

void StatusMenuPropertiesImpl::setUIMenuProperties()
{
    SDL_Color blue = { 0, 0, 255, 255 };
    SDL_Color green = { 0, 255, 0, 255 };

    // UIRenderCellDetails: backgroundColor, outlineColor, showBorderColor, showBackgroundColor, backgroundSpriteId, showbackgroundSprite
    UIRenderCellDetails gridCD = { blue, green, true, true, "brick_2", false };

    UIMenuProperties uiMenuProperties;

    uiMenuProperties.uiMenuId = "StatusMenu";
    uiMenuProperties.viewportId = "statusMenu";
    uiMenuProperties.rows = 1;
    uiMenuProperties.columns = 1;
    uiMenuProperties.xPadding = 0;
    uiMenuProperties.yPadding = 0;
    uiMenuProperties.uiRenderCellDetails = gridCD;
    uiMenuProperties.hidden = false;

    mUIMenuProperties = uiMenuProperties;
}

void StatusMenuPropertiesImpl::setButtonProperties()
{
    // orderId, buttonId, xPadding, yPadding, actionId, defaultButtonState, isSpacer
    UIButtonProperties statusMenu = { 1, "statusMenu", 20, 20, "statusMenu",  "buttonAvailable", true };

    BaseMenuProperties::setUIButtonStateProperties("statusMenu", "brick_2", false);

    mUIButtonProperties.push_back(statusMenu);
}

void StatusMenuPropertiesImpl::setUILabelProperties()
{
    // orderId, labelText, fontId, xPadding, yPadding, isSpacer. alignment
    UILabelProperties statusMenu = { 0, "Status", "Heading_1_OpenSansLight", 10, 10, false, "center" };

    mUILabelProperties.push_back(statusMenu);
}
