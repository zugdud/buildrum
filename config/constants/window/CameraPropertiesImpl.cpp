#include "include/global.hpp"

CameraPropertiesImpl::CameraPropertiesImpl()
{

}

CameraPropertiesImpl::~CameraPropertiesImpl()
{

}

void CameraPropertiesImpl::loadAll()
{
    SDL_Log("CameraPropertiesImpl::loadAll -- loading configuration ...\n");
    setCameraProperties();
}

const CameraProperties & CameraPropertiesImpl::getCameraProperties()
{
    return mCameraProperties;
}

void CameraPropertiesImpl::setCameraProperties()
{
    // CameraProperties - initPositionX, initPositionY, double defaultZoomFactor, double maxZoomFactor, double minZoomFactor;

    #ifdef LINUX_BUILD_TARGET
    CameraProperties linuxCameraProperties = { 0, 0, 1, 3.0, 1.0 };
    mCameraProperties = linuxProperties;
    #endif

    #ifdef MAC_BUILD_TARGET
    CameraProperties macCameraProperties = { 0, 0, 1, 3.0, 1.0 };
    mCameraProperties = macCameraProperties;
    #endif

    #ifdef ANDROID_BUILD_TARGET
    CameraProperties androidCameraProperties = { 0, 0, 1, 3.0, 1.0 };
    mCameraProperties = androidCameraProperties;
    #endif
}
