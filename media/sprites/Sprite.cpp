#include "include/global.hpp"

Sprite::Sprite(const int & spriteId, const SDL_Rect &rect)
{
    mSpriteId = spriteId;
    mRect = rect;
}

Sprite::~Sprite()
{

}
