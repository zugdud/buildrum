#include "include/global.hpp"

UILabel::UILabel(const UILabelProperties & uiLabelProperties, const SDL_Rect & envelope)
{
    mUILabelProperties = uiLabelProperties;
    UIElement::setRect(uiLabelProperties.xPadding, uiLabelProperties.yPadding, envelope);
    UIElement::logRectDimensions("UILabel", mUILabelProperties.labelText, UIElement::getRect());
}

UILabel::~UILabel()
{

}

const UILabelProperties & UILabel::getUILabelProperties() const
{
    return mUILabelProperties;
}
