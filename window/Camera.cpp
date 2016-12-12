#include "include/global.hpp"

Camera::Camera()
{

}

Camera::~Camera()
{

}

void Camera::configure(const Viewport & viewport, const WorldProperties & worldProperties)
{
    mCameraProperties = viewport.getViewportProperties().cameraProperties;

    mCamera.x = mCameraProperties.initPositionX;
    mCamera.y = mCameraProperties.initPositionY;
    mCamera.w = viewport.getRect().w;
    mCamera.h = viewport.getRect().h;

    mZoomFactor = mCameraProperties.defaultZoomFactor;
    mTextureSize =  worldProperties.textureSize;

    mWorldPixeWidth = mTextureSize * worldProperties.columns;
    mWorldPixelHeight = mTextureSize * worldProperties.rows;

    SDL_Log("Camera::configure -- mWorldPixeWidth: %d mWorldPixelHeight: %d mZoomFactor: %f mTextureSize: %d mCamera: [x: %d y: %d w: %d h: %d] \n",
            mWorldPixeWidth,
            mWorldPixelHeight,
            mZoomFactor,
            mTextureSize,
            mCamera.x,
            mCamera.y,
            mCamera.w,
            mCamera.h);
}


bool Camera::isViewableArea(const SDL_Rect & rect)
{
    const int padPosX = (rect.x + rect.w);
    const int padNegX = (rect.x - rect.w);
    const int padPosY = (rect.y + rect.h);
    const int padNegY = (rect.y - rect.h);

    // const int cameraX = mCamera.x / mZoomFactor;
    // const int cameraY = mCamera.y / mZoomFactor;
    // const int cameraW = mCamera.w / mZoomFactor;
    // const int cameraH = mCamera.h / mZoomFactor;

    if (padPosX >= mCamera.x  && padNegX <= (mCamera.x + mCamera.w))
    {
        if (padPosY >= mCamera.y && padNegY <= (mCamera.y + mCamera.h))
        {
            return true;
        }

    }

    return false;
}


void Camera::move(const PointDouble & pointDouble)
{
    mCamera.x += pointDouble.x;
    mCamera.y += pointDouble.y;

    // Keep the camera within the bounds of the level
    if ( mCamera.x < 0 )
    {
        mCamera.x = 0;
    }
    if ( mCamera.y < 0 )
    {
        mCamera.y = 0;
    }
    if ( mCamera.x > (mWorldPixeWidth - mCamera.w))
    {
        mCamera.x = mWorldPixeWidth - mCamera.w;
    }
    if ( mCamera.y > (mWorldPixelHeight - mCamera.h))
    {
        mCamera.y = mWorldPixelHeight - mCamera.h;
    }
}

void Camera::setZoomFactor(const double & zoomFactorAdjustment)
{
    mZoomFactor += zoomFactorAdjustment;
    if (mZoomFactor > mCameraProperties.maxZoomFactor)
    {
        mZoomFactor = mCameraProperties.maxZoomFactor;
    }
    else if (mZoomFactor < mCameraProperties.minZoomFactor)
    {
        mZoomFactor = mCameraProperties.minZoomFactor;
    }
}

const SDL_Rect & Camera::getRect()
{
    return mCamera;
}

void Camera::scrollEventCallback(SDL_Event scrollEvent)
{

}
void Camera::zoomEventCallback(const double & zoomAdjustment)
{
    SDL_Log("Camera::zoomEventCallback -- zoomAdjustment: [%f] \n", zoomAdjustment);
    setZoomFactor(zoomAdjustment);
}
