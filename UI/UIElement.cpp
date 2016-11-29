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

void UIElement::logDimensions(const std::string & name)
{
    SDL_Log("UIElement::logDimensions -- name: %s [x: %d y: %d w: %d h: %d] \n",
            name.c_str(),
            mRect.x,
            mRect.y,
            mRect.w,
            mRect.h);
}
