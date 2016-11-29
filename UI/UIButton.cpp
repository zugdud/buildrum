#include "include/global.hpp"

UIButton::UIButton(const UIButtonProperties & uiButtonProperties, const SDL_Rect & envelope, const std::vector<UIButtonStateProperties> & uiButtonStateProperties)
{
    mUIButtonProperties = uiButtonProperties;
    UIElement::setRect(mUIButtonProperties.xPadding, mUIButtonProperties.yPadding, envelope);
    addUIButtonStates(uiButtonStateProperties);
    UIElement::logRectDimensions("UIButton", mUIButtonProperties.buttonId, UIElement::getRect());
}

UIButton::~UIButton()
{

}

void UIButton::addUIButtonStates(const std::vector<UIButtonStateProperties> & uiButtonStateProperties)
{
    for (size_t i = 0; i < uiButtonStateProperties.size(); i++)
    {
        UIButtonState uiButtonState =  UIButtonState(uiButtonStateProperties[i]);
        mUIButtonStates.push_back(uiButtonState);
    }
}
