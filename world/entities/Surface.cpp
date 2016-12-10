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
    mEntityOrientation = surfaceProperties.defaultOrientation;
}

const SurfaceProperties & Surface::getSurfaceProperties()
{
    return mSurfaceProperties;
}
