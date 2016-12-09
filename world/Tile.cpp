#include "include/global.hpp"

Tile::Tile(const int & tileId)
{
    mTileId = tileId;
}

Tile::~Tile()
{

}

const Surface & Tile::getSurface()
{
    return mSurface;
}

void Tile::setSurface(const Surface & surface)
{
    mSurface = surface;
}
