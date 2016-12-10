#include "include/global.hpp"

Camera::Camera();
{

}

Camera::~Camera()
{

}

void Camera::configure(const CameraProperties &CameraProperties, const SDL_Rect & viewportRect, const WorldProperties & worldProperties)
{
    mCameraProperties = CameraProperties;

    mCamera.x = mCameraProperties.initPositionX;
    mCamera.y = mCameraProperties.initPositionY;
    mCamera.w = viewportRect.w;
    mCamera.h = viewportRect.h;

    mZoomFactor = mCameraProperties.defaultZoomFactor;
    mTextureSize =  worldProperties.textureSize;

    mWorldWidth = mTextureSize * worldProperties.columns;
    mWorldHeight = mTextureSize * worldProperties.rows;


    SDL_Log("Camera::configure -- mWorldWidth: %d mWorldHeight: %d mZoomFactor: %d mTextureSize: %d mCamera: [x: %d y: %d w: %d h: %d] \n",
            mWorldWidth,
            mWorldHeight,
            mZoomFactor,
            mTextureSize,
            mCamera.x,
            mCamera.y,
            mCamera.w,
            mCamera.h);
}


bool Camera::isViewableArea(const PointInt & pointInt)
{
    const int padPosX = (pointInt.x + mTextureSize);
    const int padNegX = (pointInt.x - mTextureSize);
    const int padPosY = (pointInt.y + mTextureSize);
    const int padNegY = (pointInt.y - mTextureSize);

    // const int cameraX = mCamera.x / mZoomFactor;
    // const int cameraY = mCamera.y / mZoomFactor;
    // const int cameraW = mCamera.w / mZoomFactor;
    // const int cameraH = mCamera.h / mZoomFactor;
    *
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
    if ( mCamera.x > (mWorldWidth - mCamera.w))
    {
        mCamera.x = mWorldWidth - mCamera.w;
    }
    if ( mCamera.y > (mWorldHeight - mCamera.h))
    {
        mCamera.y = mWorldHeight - mCamera.h;
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
