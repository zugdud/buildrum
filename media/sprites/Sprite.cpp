#include "include/global.hpp"

Sprite::Sprite(const int & spriteId, const int & linearIndex, const SDL_Rect &rect)
{
    mSpriteId = spriteId;
    mLinearIndex = linearIndex;
    mRect = rect;
}

Sprite::~Sprite()
{

}
