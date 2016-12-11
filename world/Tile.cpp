#include "include/global.hpp"

Tile::Tile()
{

}

Tile::~Tile()
{

}

void Tile::configure(const int & tileId)
{
    mTileId = tileId;
}

const Surface & Tile::getSurface() const
{
    return mSurface;
}

void Tile::setSurface(const Surface & surface)
{
    mSurface = surface;
}
