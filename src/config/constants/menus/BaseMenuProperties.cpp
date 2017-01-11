#include "include/global.hpp"

BaseMenuProperties::BaseMenuProperties()
{

}

BaseMenuProperties::~BaseMenuProperties()
{

}

const UIMenuProperties & BaseMenuProperties::getUIMenuProperties() const
{
    return mUIMenuProperties;
}
const std::vector<UIButtonProperties> & BaseMenuProperties::getUIButtonProperties()
{
    return mUIButtonProperties;
}
const std::vector<UIButtonStateProperties> & BaseMenuProperties::getUIButtonStateProperties(const std::string & buttonId)
{
    return mUIButtonStateProperties[buttonId];
}
const std::vector<UILabelProperties> & BaseMenuProperties::getUILabelProperties()
{
    return mUILabelProperties;
}

void BaseMenuProperties::setUIButtonStateProperties(const std::string & buttonId, const std::string & spriteName, const bool & showBgSprite)
{
    SDL_Color black = { 0, 0, 0, 255 };
    SDL_Color red = { 255, 0, 0, 255 };

    UIRenderCellDetails buttonSelectedCD = {  black, red, true, true, spriteName, showBgSprite  };
    UIButtonStateProperties buttonSelected = { buttonId, "buttonSelected", "buttonSelected", buttonSelectedCD };

    UIRenderCellDetails buttonAvailableCD = {  black, red, true, true, spriteName, showBgSprite  };
    UIButtonStateProperties buttonAvailable = { buttonId, "buttonAvailable", "", buttonAvailableCD };

    UIRenderCellDetails buttonCooldownCD = {  black, red, true, true, spriteName, showBgSprite  };
    UIButtonStateProperties buttonCooldown = { buttonId, "buttonCooldown",  "", buttonCooldownCD };

    UIRenderCellDetails buttonUnavailableCD = { black, red, true, true, spriteName, showBgSprite  };
    UIButtonStateProperties buttonUnavailable = { buttonId, "buttonUnavailable", "", buttonUnavailableCD };

    mUIButtonStateProperties[buttonId].push_back(buttonSelected);
    mUIButtonStateProperties[buttonId].push_back(buttonAvailable);
    mUIButtonStateProperties[buttonId].push_back(buttonCooldown);
    mUIButtonStateProperties[buttonId].push_back(buttonUnavailable);
}
