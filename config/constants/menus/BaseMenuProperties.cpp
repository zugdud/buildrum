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

void BaseMenuProperties::setUIButtonStateProperties(const std::string & buttonId, const int & spriteId, const std::string & spriteSheetIds, const bool & showBgSprite)
{
    SDL_Color black = { 0, 0, 0, 255 };
    SDL_Color red = { 255, 0, 0, 255 };
    SDL_Color green = { 0, 255, 0, 255 };

    SpriteProperties spriteProperties = { spriteId, spriteSheetIds, SDL_FLIP_NONE, 0 };
    // UIRenderCellDetails: isSpacer, backgroundColor, outlineColor, showBorderColor, showBackgroundColor, backgroundSpriteId, showbackgroundSprite
    // UIButtonStateProperties: buttonState, spriteId, soundEffectId, uiRenderCellDetails
    UIRenderCellDetails buttonSelectedCD = {  green, red, true, true, spriteProperties, showBgSprite  };
    UIButtonStateProperties buttonSelected = { buttonId, "buttonSelected", 0, "buttonSelected", buttonSelectedCD };

    UIRenderCellDetails buttonAvailableCD = {  black, red, true, true, spriteProperties, showBgSprite  };
    UIButtonStateProperties buttonAvailable = { buttonId, "buttonAvailable", 1, "", buttonAvailableCD };

    UIRenderCellDetails buttonCooldownCD = {  black, red, true, true, spriteProperties, showBgSprite  };
    UIButtonStateProperties buttonCooldown = { buttonId, "buttonCooldown", 2, "", buttonCooldownCD };

    UIRenderCellDetails buttonUnavailableCD = { black, red, true, true, spriteProperties, showBgSprite  };
    UIButtonStateProperties buttonUnavailable = { buttonId, "buttonUnavailable", 3, "", buttonUnavailableCD };

    mUIButtonStateProperties[buttonId].push_back(buttonSelected);
    mUIButtonStateProperties[buttonId].push_back(buttonAvailable);
    mUIButtonStateProperties[buttonId].push_back(buttonCooldown);
    mUIButtonStateProperties[buttonId].push_back(buttonUnavailable);
}
