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

const CameraProperties & CameraPropertiesImpl::getCameraProperties() const
{
    return mCameraProperties;
}

void CameraPropertiesImpl::setCameraProperties()
{
    // struct CameraProperties
    // {
    //     double defaultZoomFactor;
    //     double maxZoomFactor;
    //     double minZoomFactor;
    //     int initRectX;
    //     int initRectY;
    //     int initRectW;
    //     int initRectH;
    // };

    #ifdef LINUX_BUILD_TARGET
    CameraProperties linuxCameraProperties = { 1, 4.0, 1.0, 0, 0, 1280, 960 };
    mCameraProperties = linuxCameraProperties;
    #endif

    #ifdef MAC_BUILD_TARGET
    CameraProperties macCameraProperties = { 1, 4.0, 1.0, 0, 0, 1024, 768 };
    mCameraProperties = macCameraProperties;
    #endif

    #ifdef ANDROID_BUILD_TARGET
    CameraProperties androidCameraProperties = { 1, 4.0, 1.0, 0, 0, 1440, 2560 };
    mCameraProperties = androidCameraProperties;
    #endif
}
