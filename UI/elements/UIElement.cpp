#include "include/global.hpp"

UIElement::UIElement()
{
    SDL_Rect initRect = { 0, 0, 0, 0 };

    mViewportOffset = initRect;
    mRect = initRect;
}



UIElement::~UIElement()
{

}

const SDL_Rect & UIElement::getRect() const
{
    return mRect;
}

void UIElement::setRect(const int & xPadding, const int & yPadding, const SDL_Rect & envelope)
{
    mRect.x = envelope.x + xPadding;
    mRect.y = envelope.y + yPadding;
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

//
bool UIElement::isPointInRect(const PointInt & pointInt)
{
    const int offsetX = mRect.x + mViewportOffset.x;
    const int offsetY = mRect.y + mViewportOffset.y;

    // SDL_Log("UIElement::isPointInRect -- offsetX: %d offsetY: %d \n", offsetX, offsetY);
    if (pointInt.x >= offsetX && pointInt.x <= (offsetX + mRect.w) )
    {
        if (pointInt.y >= offsetY && pointInt.y <= (offsetY + mRect.h) )
        {
            return true;
        }
    }
    return false;
}
