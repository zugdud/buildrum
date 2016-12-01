#include "include/global.hpp"

FontTextures::FontTextures()
{

}

FontTextures::~FontTextures()
{

}

void FontTextures::addTexture(const std::string & text, const SDL_Rect & rect, SDL_Texture *texture)
{
    // TODO temp
    // std::string copyText = text;
    // SDL_Rect copyRect = { rect.x, rect.y, rect.w, rect.h };

    mRects.insert(std::pair<std::string, SDL_Rect>(text, rect) );
    mTextures.insert(std::pair<std::string, SDL_Texture * >(text, texture) );
}

bool FontTextures::textureExists(const std::string & text) const
{
    if (mTextures.count(text) == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

SDL_Texture * FontTextures::getTexture(const std::string & text) const
{
    return mTextures.at(text);
}
const SDL_Rect & FontTextures::getRect(const std::string & text) const
{
    return mRects.at(text);
}
