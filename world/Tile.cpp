#include "include/global.hpp"

Tile::Tile()
{

}

Tile::~Tile()
{

}

// int scaledWidth = (spriteRect.w * zoomFactor) * entitySizeFactor; // scale size of the entity
// int scaledHeight = (spriteRect.h * zoomFactor) * entitySizeFactor; // scale size of the entity
// int scaledX = ((x - cameraRect.x) * zoomFactor); // offset scaled position by the cameras position
// int scaledY = ((y - cameraRect.y) * zoomFactor); // offset scaled position by the cameras position


void Tile::updateRect(const WorldProperties & worldProperties, const double & zoomFactor, const SDL_Rect & cameraRect)
{
    const int basePosX = worldProperties.textureSize * (mTileProperties.tileId % worldProperties.columns);
    const int basePosY = worldProperties.textureSize * (mTileProperties.tileId / worldProperties.rows);

    const int x = (basePosX - cameraRect.x) * zoomFactor;
    const int y = (basePosY - cameraRect.y) * zoomFactor;
    const int w = worldProperties.textureSize * zoomFactor;
    const int h = worldProperties.textureSize * zoomFactor;

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

const bool & Tile::isViewableArea() const
{
    return mViewableArea;
}

void Tile::setViewableArea()
{
    if (Camera::Instance().isViewableArea(mRect))
    {
        mViewableArea = true;
    }
    else
    {
        mViewableArea = false;
    }
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

    mTextLabel.rect.y = (mRect.y + heightPadding);        // center y axis
    mTextLabel.rect.x = (mRect.x + widthPadding);         // center padding offset
    mTextLabel.rect.w = textureSize.w;
    mTextLabel.rect.h = textureSize.h;
}
