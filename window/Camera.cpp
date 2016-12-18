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

    mViewportRect.w = mCameraProperties.initRectW;
    mViewportRect.h = mCameraProperties.initRectH;

    mZoomFactor = mCameraProperties.defaultZoomFactor;

    SDL_Log("Camera::configure -- mZoomFactor: %f mCamera: [x: %d y: %d w: %d h: %d] \n",
            mZoomFactor,
            mCamera.x,
            mCamera.y,
            mCamera.w,
            mCamera.h);
}

const SDL_Rect & Camera::getBaseRect()
{
    return mViewportRect;
}

void Camera::resetCamera()
{
    mCamera.x = mCameraProperties.initRectX;
    mCamera.y = mCameraProperties.initRectY;
    mCamera.w = mCameraProperties.initRectW;
    mCamera.h = mCameraProperties.initRectH;
    mZoomFactor = mCameraProperties.defaultZoomFactor;
}

void Camera::updateSize(const SDL_Rect & viewportRect)
{
    mViewportRect = viewportRect;
    mCamera.w = mViewportRect.w;
    mCamera.h = mViewportRect.h;

    SDL_Log("Camera::updateSize -- mViewportRect.w: %d mViewportRect.h: %d  \n",
            mViewportRect.w,
            mViewportRect.h);
}

void Camera::registerObserver(CameraObserver *CameraObserver)
{
    mObservers.push_back(CameraObserver);
    SDL_Log("Camera::registerObserver -- observer added, count: %zu \n", mObservers.size());
}

bool Camera::isViewableArea(const SDL_Rect & rect)
{
    if ((rect.x + rect.w) >= 0  && (rect.x - rect.w) <= mViewportRect.w)
    {
        if ((rect.y + rect.h) >= 0 && (rect.y - rect.h) <= mViewportRect.h)
        {
            return true;
        }
    }
    return false;
}

void Camera::setPosition(const PointInt & pointMovement)
{
    const int & textureSize = WorldManager::Instance().getWorld().getWorldProperties().textureSize;
    const int & worldPixeWidth = textureSize * WorldManager::Instance().getWorld().getWorldProperties().columns;
    const int & worldPixeHeight  = textureSize * WorldManager::Instance().getWorld().getWorldProperties().rows;

    mCamera.x += pointMovement.x;
    mCamera.y += pointMovement.y;
    mCamera.w = mViewportRect.w / mZoomFactor;
    mCamera.h = mViewportRect.h / mZoomFactor;

    // Keep the camera within the bounds of the level
    if ( mCamera.x > (worldPixeWidth - mCamera.w))
    {
        mCamera.x = worldPixeWidth - mCamera.w;
    }
    if ( mCamera.y > (worldPixeHeight - mCamera.h))
    {
        mCamera.y = worldPixeHeight - mCamera.h;
    }
    if ( mCamera.x < 0 )
    {
        mCamera.x = 0;
    }
    if ( mCamera.y < 0 )
    {
        mCamera.y = 0;
    }
    //
    // SDL_Log("Camera::setPosition -- edgeX: %d edgeY: %d mCamera: [x: %d y: %d w: %d h: %d] \n",
    //         mCamera.x + mCamera.w,
    //         mCamera.y + mCamera.h,
    //         mCamera.x,
    //         mCamera.y,
    //         mCamera.w,
    //         mCamera.h);
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
    PointInt pointInt = { 0, 0 };
    setPosition(pointInt);
}

void Camera::dispatchPositionUpdate()
{
    for (size_t i = 0; i < mObservers.size(); i++)
    {
        mObservers[i]->positionUpdate();
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
    // SDL_Log("Camera::scrollEventCallback -- pointMovement: [x: %d, y: %d] \n", pointMovement.x, pointMovement.y);
    setPosition(pointMovement);
    dispatchPositionUpdate();
}
void Camera::zoomEventCallback(const double & zoomAdjustment)
{
    // SDL_Log("Camera::zoomEventCallback -- zoomAdjustment: [%f] \n", zoomAdjustment);
    setZoomFactor(zoomAdjustment);
    dispatchZoomFactorUpdate();
}
