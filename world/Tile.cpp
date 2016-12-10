#include "include/global.hpp"

Tile::Tile()
{

}

Tile::~Tile()
{

}

void configure(const int & tileId)
{
    mTileId = tileId;
}

const Surface & Tile::getSurface()
{
    return mSurface;
}

void Tile::setSurface(const Surface & surface)
{
    mSurface = surface;
}
