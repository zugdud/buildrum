#include "include/global.hpp"

UIElement::UIElement()
{

}



UIElement::~UIElement()
{

}

const SDL_Rect & UIElement::getRect()
{
    return mRect;
}

void UIElement::setRect(const int & xPadding, const int & yPadding, const SDL_Rect & envelope)
{
    mRect.x = xPadding;
    mRect.y = yPadding;
    mRect.w = envelope.w - (xPadding * 2);
    mRect.h = envelope.h - (yPadding * 2);
}

void UIElement::logRectDimensions(const std::string & elementType, const std::string & elementName, const SDL_Rect & rect)
{
    SDL_Log("UIElement::logRectDimensions -- type: %s name: %s [x: %d y: %d w: %d h: %d] \n",
            elementType.c_str(),
            elementName.c_str(),
            rect.x,
            rect.y,
            rect.w,
            rect.h);
}
