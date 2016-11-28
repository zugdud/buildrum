#include "include/global.hpp"

Camera::Camera(const CameraProperties &CameraProperties, const WindowProperties &windowProperties);
{
    mCameraProperties = CameraProperties;
    initCamera(windowProperties);
}

Camera::~Camera()
{

}

void Camera::initCamera(const WindowProperties &windowProperties)
{
    mCamera.x = mCameraProperties.initPositionX;
    mCamera.y = mCameraProperties.initPositionY;
    mCamera.w = windowProperties.screenWidth;
    mCamera.h = windowProperties.screenHeight;

    mZoomFactor = mCameraProperties.defaultZoomFactor;
    mWorldWidth = 0;
    mWorldHeight = 0;
}


Camera::~Camera()
{
    dtor();
}

bool Camera::isWithinPaddedCameraArea(const int & x, const int & y, const int & pixelsPerSprite)
{
    const int padPosX = (x + pixelsPerSprite);
    const int padNegX = (x - pixelsPerSprite);
    const int padPosY = (y + pixelsPerSprite);
    const int padNegY = (y - pixelsPerSprite);

    // const int cameraX = mCamera.x / mZoomFactor;
    // const int cameraY = mCamera.y / mZoomFactor;
    // const int cameraW = mCamera.w / mZoomFactor;
    // const int cameraH = mCamera.h / mZoomFactor;

    const int cameraX = mCamera.x;
    const int cameraY = mCamera.y;
    const int cameraW = mCamera.w;
    const int cameraH = mCamera.h;

    if (padPosX >= cameraX && padNegX <= (cameraW + cameraX))
    {
        if (padPosY >= cameraY && padNegY <= (cameraH + cameraY))
        {
            return true;
        }

    }

    return false;

}


void Camera::moveCamera(float velX, float velY)
{
    mCamera.x += velX;
    mCamera.y += velY;

    // Keep the camera within the bounds of the level
    if ( mCamera.x < 0 )
    {
        mCamera.x = 0;
    }
    if ( mCamera.y < 0 )
    {
        mCamera.y = 0;
    }
    if ( mCamera.x > (mLevelWidth - mCamera.w))
    {
        mCamera.x = mLevelWidth - mCamera.w;
    }
    if ( mCamera.y > (mLevelHeight - mCamera.h))
    {
        mCamera.y = mLevelHeight - mCamera.h;
    }
}

void Camera::setZoomFactor(float zoomFactor)
{
    mZoomFactor += zoomFactor;
    if (mZoomFactor > G_CAMERA_MAXZOOM)
    {
        mZoomFactor = G_CAMERA_MAXZOOM;
    }
    else if (mZoomFactor < G_CAMERA_MINZOOM)
    {
        mZoomFactor = G_CAMERA_MINZOOM;
    }
}

float Camera::getZoomFactor()
{
    return mZoomFactor;
}

SDL_Rect Camera::getBox()
{
    return mCamera;
}

int Camera::getX()
{
    return mCamera.x;
}

int Camera::getY()
{
    return mCamera.y;
}
