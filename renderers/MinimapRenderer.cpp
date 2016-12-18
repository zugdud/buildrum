#include "include/global.hpp"

MinimapRenderer::MinimapRenderer()
{
    mSDLRenderer = WindowManager::getInstance()->getSDLRenderer();
    mAttached = false;
    mScaleRatio = 1.0;
    mBackgroundTexture = NULL;
}

MinimapRenderer::~MinimapRenderer()
{

}

const bool & MinimapRenderer::isAttached()
{
    return mAttached;
}

void MinimapRenderer::attach(const Viewport &viewport)
{
    mAttached = true;

    SDL_Log("MinimapRenderer::attached -- creating background texture ... \n");
    createBackgroundTexture(viewport);
}

void MinimapRenderer::createBackgroundTexture(const Viewport &viewport)
{
    Camera::Instance().resetCamera();

    SDL_Rect borderRect =  { 0, 0, viewport.getRect().w, viewport.getRect().h };

    mBorderRect = borderRect;

    const WorldProperties & worldProperties =  WorldManager::Instance().getWorld().getWorldProperties();
    const double tileSize = viewport.getRect().h / worldProperties.rows;
    const double percentDecrease = (worldProperties.textureSize - tileSize) / worldProperties.textureSize * 100;

    mScaleRatio = (100 - percentDecrease) / 100;
    SDL_Log("MinimapRenderer::createBackgroundTexture -- mScaleRatio: %f \n", mScaleRatio);

    const std::vector<Tile> & tiles = WorldManager::Instance().getWorld().getTiles();
    for (size_t tileId = 0; tileId < tiles.size(); tileId++)
    {
        const SDL_Rect tileRect = tiles[tileId].getRect();
        SDL_Rect minimapRect;
        minimapRect.x = ceil(tileRect.x * mScaleRatio);
        minimapRect.y = ceil(tileRect.y * mScaleRatio);
        minimapRect.w = ceil(tileRect.w * mScaleRatio);
        minimapRect.h = ceil(tileRect.h * mScaleRatio);

        // SDL_Log("MinimapRenderer::createBackgroundTexture -- tileRect: [x: %d y: %d w: %d h: %d] \n",
        //         tileRect.x,
        //         tileRect.y,
        //         tileRect.w,
        //         tileRect.h);
        // SDL_Log("MinimapRenderer::createBackgroundTexture -- minimapRect: [x: %d y: %d w: %d h: %d] \n",
        //         minimapRect.x,
        //         minimapRect.y,
        //         minimapRect.w,
        //         minimapRect.h);

        renderLayers(tiles[tileId], minimapRect);
    }

    createBGTexture(viewport);
}

// TODO configs
void MinimapRenderer::createBGTexture(const Viewport &viewport)
{
    SDL_Surface *sshot = SDL_CreateRGBSurface(0, viewport.getRect().w, viewport.getRect().h, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);

    if (sshot != NULL)
    {
        SDL_Rect rendRect = { 0, 0, viewport.getRect().w, viewport.getRect().h };
        if (SDL_RenderReadPixels(mSDLRenderer, &rendRect, SDL_PIXELFORMAT_ARGB8888, sshot->pixels, sshot->pitch) == 0)
        {
            mBackgroundTexture = SDL_CreateTextureFromSurface(mSDLRenderer, sshot);
            if (mBackgroundTexture == NULL)
            {
                SDL_Log("MinimapRenderer::createBGTexture --  SDL_CreateTextureFromSurface error: %s  \n", SDL_GetError());
            }
        }
        SDL_FreeSurface(sshot);
    }
    else
    {
        SDL_Log("MinimapRenderer::createBGTexture --  SDL_CreateRGBSurface error: %s \n", SDL_GetError());
    }
}

void MinimapRenderer::detatch()
{
    mAttached = false;
}

void MinimapRenderer::render()
{
    if (mAttached)
    {
        renderBackground();
        renderBorder();
        renderCamera();
    }
}

// TODO configs
void MinimapRenderer::renderBorder()
{
    SDL_SetRenderDrawColor(mSDLRenderer, 0, 255, 0, 255);
    SDL_RenderDrawRect(mSDLRenderer, &mBorderRect);
}

void MinimapRenderer::renderCamera()
{
    SDL_Rect scaledRect;

    // const double & zoomFactor = Camera::Instance().getZoomFactor();
    // const double & scaleFactor = mCameraScaleRatio / zoomFactor;

    scaledRect.x = ceil(Camera::Instance().getRect().x * mScaleRatio);
    scaledRect.y = ceil(Camera::Instance().getRect().y * mScaleRatio);
    scaledRect.w = ceil(Camera::Instance().getRect().w * mScaleRatio);
    scaledRect.h = ceil(Camera::Instance().getRect().h * mScaleRatio);
    //
    // SDL_Log("MinimapRenderer::renderCamera POST-- zoomFactor: %f mCameraScaleRatio: %f scaledRect: [x: %d y: %d w: %d h: %d] \n",
    //         zoomFactor,
    //         mCameraScaleRatio,
    //         scaledRect.x,
    //         scaledRect.y,
    //         scaledRect.w,
    //         scaledRect.h);

    SDL_SetRenderDrawColor(mSDLRenderer, 0, 0, 255, 255);
    SDL_RenderDrawRect(mSDLRenderer, &scaledRect);
}

void MinimapRenderer::renderLayers(const Tile & tile, const SDL_Rect & rect)
{
    const std::vector<SpriteProperties> & spriteProperties = tile.getSurface().getSpriteProperties();

    for (size_t i = 0; i < spriteProperties.size(); i++)
    {
        renderSprite(spriteProperties[i], rect);
    }
}

void MinimapRenderer::renderBackground()
{
    SDL_RenderCopy(mSDLRenderer, mBackgroundTexture, NULL, NULL);
}


void MinimapRenderer::renderSprite(const SpriteProperties & spriteProperties, const SDL_Rect & destRect)
{
    SDL_Point *center = NULL;
    SDL_Texture *spriteSheetTexture = SpriteSheetManager::Instance().getSpriteSheet(spriteProperties.spriteSheetId).getTexture();
    const SDL_Rect & spriteRect = SpriteSheetManager::Instance().getSpriteSheet(spriteProperties.spriteSheetId).getSprite(spriteProperties.spriteId).getRect();

    SDL_RenderCopyEx(mSDLRenderer,
                     spriteSheetTexture,
                     &spriteRect,
                     &destRect,
                     spriteProperties.angle,
                     center,
                     spriteProperties.sdlRendererFlip);
}
