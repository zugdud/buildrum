#include "include/global.hpp"

UILabel::UILabel(const UILabelProperties & uiLabelProperties, const SDL_Rect & envelope)
{
    mUILabelProperties = uiLabelProperties;
    UIElement::setRect(uiLabelProperties.xPadding, uiLabelProperties.yPadding, envelope);
}

UILabel::~UILabel()
{

}
