#include "include/global.hpp"

UIButton::UIButton(const UIButtonProperties & uiButtonProperties, const SDL_Rect & envelope, const std::vector<UIButtonStateProperties> & uiButtonStateProperties)
{
    mUIButtonProperties = uiButtonProperties;
    UIElement::setRect(mUIButtonProperties.xPadding, mUIButtonProperties.yPadding, envelope);
    addUIButtonStates(uiButtonStateProperties);
    UIElement::logRectDimensions("UIButton", mUIButtonProperties.buttonId, UIElement::getRect());

    setDefaultButtonState();
}

UIButton::~UIButton()
{

}


bool UIButton::setDefaultButtonState()
{

    for (size_t i = 0; i < mUIButtonStates.size(); i++)
    {
        if (mUIButtonStates[i].mUIButtonStateProperties.getUIButtonStateProperties() == mUIButtonProperties.defaultButtonState)
        {
            mCurrentUIButtonState = mUIButtonStates[i];
            return true;
        }
    }

    SDL_Log("UIButton::setDefaultButtonState -- ERROR: defaultButtonState: %s not found in mUIButtonStates \n", mUIButtonProperties.defaultButtonState);
    return false;
}

const UIButtonProperties & UIButton::getUIButtonProperties() const
{
    return mUIButtonProperties;
}

const UIButtonState & UIButton::getCurrentUIButtonState() const
{
    return mCurrentUIButtonState;
}

void UIButton::addUIButtonStates(const std::vector<UIButtonStateProperties> & uiButtonStateProperties)
{
    for (size_t i = 0; i < uiButtonStateProperties.size(); i++)
    {
        UIButtonState uiButtonState =  UIButtonState(uiButtonStateProperties[i]);
        mUIButtonStates.push_back(uiButtonState);
    }
}
