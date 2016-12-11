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
