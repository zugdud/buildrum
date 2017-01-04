#include "include/global.hpp"

UILabel::UILabel(const UILabelProperties & uiLabelProperties)
{
    mUILabelProperties = uiLabelProperties;
}

UILabel::~UILabel()
{

}

void UILabel::updateEnvelope(const SDL_Rect &envelope)
{
    UIElement::setRect(mUILabelProperties.xPadding, mUILabelProperties.yPadding, envelope);
    UIElement::logRectDimensions("UILabel", mUILabelProperties.labelText, UIElement::getRect());
}

const UILabelProperties & UILabel::getUILabelProperties() const
{
    return mUILabelProperties;
}
