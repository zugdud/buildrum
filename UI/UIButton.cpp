#include "include/global.hpp"

UIButton::UIButton(const UIButtonProperties & uiButtonProperties,
                   const SDL_Rect & envelope,
                   const std::vector<UIButtonStateProperties> & uiButtonStateProperties)
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
    // check that the defaultButtonState exists
    if (mUIButtonStates.count(mUIButtonProperties.defaultButtonState) == 1)
    {
        mCurrentUIButtonStateId = mUIButtonProperties.defaultButtonState;
        return true;
    }
    else
    {
        mCurrentUIButtonStateId = "unknown";
        SDL_Log("UIButton::setDefaultButtonState -- ERROR: defaultButtonState: %s not found in mUIButtonStates \n", mUIButtonProperties.defaultButtonState.c_str());
        return false;
    }
}

const UIButtonProperties & UIButton::getUIButtonProperties() const
{
    return mUIButtonProperties;
}

const UIButtonState & UIButton::getCurrentUIButtonState() const
{
    return mUIButtonStates.at(mCurrentUIButtonStateId);
}

void UIButton::addUIButtonStates(const std::vector<UIButtonStateProperties> & uiButtonStateProperties)
{
    for (size_t i = 0; i < uiButtonStateProperties.size(); i++)
    {
        UIButtonState uiButtonState =  UIButtonState(uiButtonStateProperties[i]);
        mUIButtonStates.insert(std::pair<std::string, UIButtonState>(uiButtonState.getUIButtonStateProperties().buttonStateId, uiButtonState) );
    }
}
