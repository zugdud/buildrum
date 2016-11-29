#include "include/global.hpp"

UIElement::UIElement(const int & xPadding, const int & yPadding, const SDL_Rect & envelope)
{
    mRect.x = xPadding;
    mRect.y = yPadding;
    mRect.w = envelope.w - (xPadding * 2);
    mRect.h = envelope.h - (yPadding * 2);
}

UIElement::~UIElement()
{

}
