#include "include/global.hpp"

MinimapRenderer::MinimapRenderer()
{
    mSDLRenderer = WindowManager::getInstance()->getSDLRenderer();
    mAttached = false;
    mScaleRatio = 1.0;
    mBackgroundTexture = NULL;
    mMinimapTileSize = 0;
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

    SDL_Rect borderRect = { 0, 0, viewport.getRect().w, viewport.getRect().h };
    mBorder = borderRect;

    Camera::Instance().resetCamera();
    SDL_Log("----------------------------------------------------\n");
    SDL_Log("MinimapRenderer::attached -- setting up ... \n");
    calcScale();
    buildAtlas();
    SDL_Log("----------------------------------------------------\n");
}

// worldProperties.rows = 64;
// worldProperties.columns = 64;
// worldProperties.numTiles = 4096;
// worldProperties.textureSize = 32;
void MinimapRenderer::calcScale()
{
    const WorldProperties & worldProperties =  WorldManager::Instance().getWorld().getWorldProperties();

    mMinimapTileSize = mBorder.w / worldProperties.columns;

    mScaleRatio = (double) mMinimapTileSize / worldProperties.textureSize;

    SDL_Log("MinimapRenderer::calcScale --  mMinimapTileSize: %d mScaleRatio: %f \n",
            mMinimapTileSize,
            mScaleRatio);

    const int minimapSize = mMinimapTileSize * worldProperties.columns;
    const int minimapPadX = (mBorder.w - minimapSize) / 2;
    const int minimapPadY = (mBorder.h - minimapSize) / 2;

    SDL_Rect borderRect =  { minimapPadX, minimapPadY, minimapSize, minimapSize };

    mMinimap = borderRect;

    SDL_Log("MinimapRenderer::calcScale --  Minimap Viewport: [x: %d y: %d w: %d h: %d]  Minimap Texture: [x: %d y: %d w: %d h: %d] \n",
            mBorder.x,
            mBorder.y,
            mBorder.w,
            mBorder.h,
            mMinimap.x,
            mMinimap.y,
            mMinimap.w,
            mMinimap.h);
}

// TODO configs
void MinimapRenderer::createAtlasTexture()
{
    SDL_Surface *sshot = SDL_CreateRGBSurface(0, mMinimap.w, mMinimap.h, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);

    if (sshot != NULL)
    {
        SDL_Rect rendRect = { 0, 0, mMinimap.w, mMinimap.h };
        if (SDL_RenderReadPixels(mSDLRenderer, &rendRect, SDL_PIXELFORMAT_ARGB8888, sshot->pixels, sshot->pitch) == 0)
        {
            mBackgroundTexture = SDL_CreateTextureFromSurface(mSDLRenderer, sshot);
            if (mBackgroundTexture == NULL)
            {
                SDL_Log("MinimapRenderer::createBGTexture --  SDL_CreateTextureFromSurface error: %s  \n", SDL_GetError());
            }
            else
            {
                SDL_SaveBMP(sshot, "atlas.bmp");
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
        renderBorder();
        renderBackground();
        renderCamera();
    }
}

// TODO configs
void MinimapRenderer::renderBorder()
{
    SDL_SetRenderDrawColor(mSDLRenderer, 0, 255, 0, 255);
    SDL_RenderFillRect(mSDLRenderer, &mBorder);
}

void MinimapRenderer::renderCamera()
{
    SDL_Rect scaledRect;

    // const double & zoomFactor = Camera::Instance().getZoomFactor();
    // const double & scaleFactor = mCameraScaleRatio / zoomFactor;

    scaledRect.x = floor(Camera::Instance().getRect().x * mScaleRatio) + mMinimap.x;
    scaledRect.y = floor(Camera::Instance().getRect().y * mScaleRatio) + mMinimap.y;
    scaledRect.w = floor(Camera::Instance().getRect().w * mScaleRatio);
    scaledRect.h = floor(Camera::Instance().getRect().h * mScaleRatio);
    //

    SDL_SetRenderDrawColor(mSDLRenderer, 0, 0, 255, 255);
    SDL_RenderDrawRect(mSDLRenderer, &scaledRect);
}

void MinimapRenderer::renderBackground()
{
    SDL_Rect sourceRect = { 0, 0, mMinimap.w, mMinimap.h };

    SDL_RenderCopy(mSDLRenderer, mBackgroundTexture, &sourceRect, &mMinimap);
}

void MinimapRenderer::renderText(const Tile & tile)
{
    SDL_Texture *labelTexture = tile.getTextLabel().labelTexture;
    const SDL_Rect & destRect = tile.getTextLabel().rect;

    SDL_RenderCopy(mSDLRenderer, labelTexture, NULL, &destRect);
}

// create atlas
void MinimapRenderer::buildAtlas()
{
    const WorldProperties & worldProperties =  WorldManager::Instance().getWorld().getWorldProperties();
    const std::vector<Tile> & tiles = WorldManager::Instance().getWorld().getTiles();

    for (size_t tileId = 0; tileId < tiles.size(); tileId++)
    {
        int col = tileId % worldProperties.columns;
        int row = tileId / worldProperties.rows;

        SDL_Rect destRect;
        destRect.x = mMinimapTileSize * col;
        destRect.y = mMinimapTileSize * row;
        destRect.w = mMinimapTileSize;
        destRect.h = mMinimapTileSize;

        renderAtlasSurface(tiles[tileId], destRect);
        // renderText(tiles[tileId]);
    }
    createAtlasTexture();
}

void MinimapRenderer::renderAtlasSurface(const Tile & tile, const SDL_Rect & destRect)
{
    const std::vector<SpriteProperties> & spriteProperties = tile.getSurface().getSpriteProperties();

    for (size_t i = 0; i < spriteProperties.size(); i++)
    {
        renderSprite(spriteProperties[i], destRect);
    }
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
