#include "include/global.hpp"

UIButtonState::UIButtonState(const UIButtonStateProperties & uiButtonStateProperties)
{
    mUIButtonStateProperties = uiButtonStateProperties;
}

UIButtonState::~UIButtonState()
{

}

const UIButtonStateProperties & UIButtonState::getUIButtonStateProperties() const
{
    return mUIButtonStateProperties;
}
