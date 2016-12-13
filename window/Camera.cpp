#include "include/global.hpp"

Camera::Camera()
{

}

Camera::~Camera()
{

}

void Camera::configure(const CameraProperties & cameraProperties)
{
    mCameraProperties = cameraProperties;

    mCamera.x = mCameraProperties.initRectX;
    mCamera.y = mCameraProperties.initRectY;
    mCamera.w = mCameraProperties.initRectW;
    mCamera.h = mCameraProperties.initRectH;

    mZoomFactor = mCameraProperties.defaultZoomFactor;

    SDL_Log("Camera::configure -- mZoomFactor: %f mCamera: [x: %d y: %d w: %d h: %d] \n",
            mZoomFactor,
            mCamera.x,
            mCamera.y,
            mCamera.w,
            mCamera.h);
}

void Camera::updateSize(const SDL_Rect & viewportRect)
{
    mCamera.w = viewportRect.w;
    mCamera.h = viewportRect.h;
    SDL_Log("Camera::updateSize --  mCamera: [x: %d y: %d w: %d h: %d] \n",
            mCamera.x,
            mCamera.y,
            mCamera.w,
            mCamera.h);
}

void Camera::registerObserver(CameraObserver *CameraObserver)
{
    mObservers.push_back(CameraObserver);
    SDL_Log("Camera::registerObserver -- observer added, count: %zu \n", mObservers.size());
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

void Camera::move(const PointInt & pointMovement)
{
    const int & textureSize = WorldManager::Instance().getWorld().getWorldProperties().textureSize;
    const int & worldPixeWidth = textureSize * WorldManager::Instance().getWorld().getWorldProperties().columns;
    const int & worldPixeHeight  = textureSize * WorldManager::Instance().getWorld().getWorldProperties().rows;

    mCamera.x += pointMovement.x;
    mCamera.y += pointMovement.y;

    // Keep the camera within the bounds of the level
    if ( mCamera.x < 0 )
    {
        mCamera.x = 0;
    }
    if ( mCamera.y < 0 )
    {
        mCamera.y = 0;
    }
    if ( mCamera.x > (worldPixeWidth - mCamera.w))
    {
        mCamera.x = worldPixeWidth - mCamera.w;
    }
    if ( mCamera.y > (worldPixeHeight - mCamera.h))
    {
        mCamera.y = worldPixeHeight - mCamera.h;
    }

    SDL_Log("Camera::move --  mCamera: [x: %d y: %d w: %d h: %d] \n",
            mCamera.x,
            mCamera.y,
            mCamera.w,
            mCamera.h);
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

void Camera::dispatchZoomFactorUpdate()
{
    for (size_t i = 0; i < mObservers.size(); i++)
    {
        mObservers[i]->zoomFactorUpdate();
    }
}

const SDL_Rect & Camera::getRect()
{
    return mCamera;
}

const double & Camera::getZoomFactor()
{
    return mZoomFactor;
}

void Camera::scrollEventCallback(const PointInt & pointMovement)
{
    SDL_Log("Camera::scrollEventCallback -- pointMovement: [x: %d, y: %d] \n", pointMovement.x, pointMovement.y);
    move(pointMovement);
}
void Camera::zoomEventCallback(const double & zoomAdjustment)
{
    SDL_Log("Camera::zoomEventCallback -- zoomAdjustment: [%f] \n", zoomAdjustment);
    setZoomFactor(zoomAdjustment);
    dispatchZoomFactorUpdate();
}
