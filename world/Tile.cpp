#include "include/global.hpp"

Tile::Tile()
{

}

Tile::~Tile()
{

}


void Tile::updateRect(const WorldProperties & worldProperties)
{
    const int x = worldProperties.textureSize * (mTileProperties.tileId % worldProperties.columns);
    const int y = worldProperties.textureSize * (mTileProperties.tileId / worldProperties.rows);
    const int w = worldProperties.textureSize;
    const int h = worldProperties.textureSize;

    SDL_Rect rect = { x, y, w, h };

    mRect = rect;
}

void Tile::configure(const TileProperties & tileProperties)
{
    mTileProperties = tileProperties;
}

const TileProperties & Tile::getTileProperties() const
{
    return mTileProperties;
}

const Surface & Tile::getSurface() const
{
    return mSurface;
}

void Tile::setSurface(const Surface & surface)
{
    mSurface = surface;
}

const SDL_Rect & Tile::getRect() const
{
    return mRect;
}

const TextLabel & Tile::getTextLabel() const
{
    return mTextLabel;
}

void Tile::updateLabel()
{
    std::string tileIdString;
    std::ostringstream convert;

    convert << mTileProperties.tileId;
    tileIdString = convert.str();

    FontTextures & fontTextures = FontManager::getInstance()->getTextures(mTileProperties.fontProfileName, tileIdString);

    mTextLabel.labelTexture = fontTextures.getTexture(tileIdString);
    const SDL_Rect & textureSize = fontTextures.getRect(tileIdString);

    const int heightPadding = (mRect.h - textureSize.h) / 2;
    const int widthPadding = (mRect.w - textureSize.w) / 2;

    mTextLabel.rect.y = mRect.y + heightPadding;        // center y axis

    mTextLabel.rect.x = mRect.x + widthPadding;         // center padding offset
    mTextLabel.rect.w = textureSize.w;
    mTextLabel.rect.h = textureSize.h;
}
