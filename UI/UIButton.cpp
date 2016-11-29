#include "include/global.hpp"

UIButton::UIButton(const UIButtonProperties & uiButtonProperties, const SDL_Rect & envelope, const std::vector<UIButtonStateProperties> & uiButtonStateProperties)
{
    mUIButtonProperties = uiButtonProperties;
    UIElement::setRect(UIButtonProperties.xPadding, UIButtonProperties.yPadding, envelope);
    addUIButtonStates(const std::vector<UIButtonStateProperties> &uiButtonStateProperties);
    UIElement::logDimensions(mUIButtonProperties.uiMenuId);
}

UIButton::~UIButton()
{

}

void UIButton::addUIButtonStates(const std::vector<UIButtonStateProperties> & uiButtonStateProperties)
{
    for (size_t i = 0; i < uiButtonStateProperties.size(); i++)
    {
        mUIButtonStates.push_back(new ButtonState(uiButtonStateProperties[i]));
    }
}
