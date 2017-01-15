#include "include/global.hpp"

UIButtonState::UIButtonState()
{

}

UIButtonState::~UIButtonState()
{

}

void UIButtonState::configure(const UIButtonStateProperties &uiButtonStateProperties)
{
    mUIButtonStateProperties = uiButtonStateProperties;
}

const UIButtonStateProperties & UIButtonState::getUIButtonStateProperties() const
{
    return mUIButtonStateProperties;
}

void UIButtonState::updateSpriteName(const std::string & spriteName)
{
    mUIButtonStateProperties.uiRenderCellDetails.spriteName = spriteName;
}
