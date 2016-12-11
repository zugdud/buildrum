#include "include/global.hpp"

Surface::Surface()
{

}

Surface::~Surface()
{

}

void Surface::configure(const SurfaceProperties & surfaceProperties)
{

    mSurfaceProperties =  surfaceProperties;
    mEntityOrientation = surfaceProperties.entityProperties.defaultOrientation;
}

const SurfaceProperties & Surface::getSurfaceProperties() const
{
    return mSurfaceProperties;
}
