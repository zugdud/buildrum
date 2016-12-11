#include "include/global.hpp"

Sprite::Sprite(const int & spriteId, const SDL_Rect &rect)
{
    mSpriteId = spriteId;
    mRect = rect;
}

Sprite::~Sprite()
{

}

const int & Sprite::getSpriteId() const
{
    return mSpriteId;
}
const SDL_Rect & Sprite::getRect() const
{
    return mRect;
}
