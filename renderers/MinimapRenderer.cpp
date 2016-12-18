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

// worldProperties.rows = 64;
// worldProperties.columns = 64;
// worldProperties.numTiles = 4096;
// worldProperties.textureSize = 32;

// minimap 144
void MinimapRenderer::createBackgroundTexture(const Viewport &viewport)
{
    Camera::Instance().resetCamera();

    SDL_Rect borderRect =  { 0, 0, viewport.getRect().w, viewport.getRect().h };

    mBorderRect = borderRect;

    const WorldProperties & worldProperties =  WorldManager::Instance().getWorld().getWorldProperties();

    const int minimapRectSize = viewport.getRect().w / worldProperties.columns;
    const double minimapScaleRatio = (double) minimapRectSize / worldProperties.textureSize;
    mScaleRatio = minimapScaleRatio;

    SDL_Log("MinimapRenderer::createBackgroundTexture -- minimapRectSize: %d minimapScaleRatio: %f Minimap: [w: %d h: %d] \n",
            minimapRectSize,
            minimapScaleRatio,
            mBorderRect.w,
            mBorderRect.h);

    const std::vector<Tile> & tiles = WorldManager::Instance().getWorld().getTiles();
    for (size_t tileId = 0; tileId < tiles.size(); tileId++)
    {
        renderLayers(tiles[tileId]);
        // renderText(tiles[tileId]);
    }

    createMinimapTexture(viewport);
}

// TODO configs
void MinimapRenderer::createMinimapTexture(const Viewport &viewport)
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

// // TODO configs
// void MinimapRenderer::createAtlas()
// {
//     const WorldProperties & worldProperties =  WorldManager::Instance().getWorld().getWorldProperties();
//     const int vpWidth = worldProperties.columns * worldProperties.textureSize;
//     const int worldHeight = worldProperties.rows * worldProperties.textureSize;
//
//     SDL_Surface *sshot = SDL_CreateRGBSurface(0, worldWidth, worldHeight, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
//
//     if (sshot != NULL)
//     {
//         SDL_Rect rendRect = { 0, 0, worldWidth, worldHeight };
//         if (SDL_RenderReadPixels(mSDLRenderer, &rendRect, SDL_PIXELFORMAT_ARGB8888, sshot->pixels, sshot->pitch) == 0)
//         {
//             mBackgroundTexture = SDL_CreateTextureFromSurface(mSDLRenderer, sshot);
//             if (mBackgroundTexture == NULL)
//             {
//                 SDL_Log("MinimapRenderer::createBGTexture --  SDL_CreateTextureFromSurface error: %s  \n", SDL_GetError());
//             }
//             else
//             {
//                 SDL_SaveBMP(sshot, "atlas.bmp");
//             }
//         }
//         SDL_FreeSurface(sshot);
//     }
//     else
//     {
//         SDL_Log("MinimapRenderer::createBGTexture --  SDL_CreateRGBSurface error: %s \n", SDL_GetError());
//     }
// }

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

    scaledRect.x = floor(Camera::Instance().getRect().x * mScaleRatio);
    scaledRect.y = floor(Camera::Instance().getRect().y * mScaleRatio);
    scaledRect.w = floor(Camera::Instance().getRect().w * mScaleRatio);
    scaledRect.h = floor(Camera::Instance().getRect().h * mScaleRatio);
    //

    SDL_SetRenderDrawColor(mSDLRenderer, 0, 0, 255, 255);
    SDL_RenderDrawRect(mSDLRenderer, &scaledRect);
}

void MinimapRenderer::renderBackground()
{
    SDL_RenderCopy(mSDLRenderer, mBackgroundTexture, NULL, NULL);
}

void MinimapRenderer::renderText(const Tile & tile)
{
    SDL_Texture *labelTexture = tile.getTextLabel().labelTexture;
    const SDL_Rect & destRect = tile.getTextLabel().rect;

    SDL_RenderCopy(mSDLRenderer, labelTexture, NULL, &destRect);
}


void MinimapRenderer::renderLayers(const Tile & tile)
{
    const std::vector<SpriteProperties> & spriteProperties = tile.getSurface().getSpriteProperties();

    for (size_t i = 0; i < spriteProperties.size(); i++)
    {
        renderSprite(spriteProperties[i], tile.getRect());
    }
}

void MinimapRenderer::renderSprite(const SpriteProperties & spriteProperties, const SDL_Rect & destRect)
{

    SDL_Rect minimapRect;

    minimapRect.x = floor(destRect.x * mScaleRatio);
    minimapRect.y = floor(destRect.y * mScaleRatio);
    minimapRect.w = floor(destRect.w * mScaleRatio);
    minimapRect.h = floor(destRect.h * mScaleRatio);

    if (minimapRect.x > 144)
    {
        SDL_Log(" minimapRect: [x: %d y: %d w: %d h: %d] \n",
                minimapRect.x,
                minimapRect.y,
                minimapRect.w,
                minimapRect.h);
    }

    SDL_Point *center = NULL;
    SDL_Texture *spriteSheetTexture = SpriteSheetManager::Instance().getSpriteSheet(spriteProperties.spriteSheetId).getTexture();
    const SDL_Rect & spriteRect = SpriteSheetManager::Instance().getSpriteSheet(spriteProperties.spriteSheetId).getSprite(spriteProperties.spriteId).getRect();

    SDL_RenderCopyEx(mSDLRenderer,
                     spriteSheetTexture,
                     &spriteRect,
                     &minimapRect,
                     spriteProperties.angle,
                     center,
                     spriteProperties.sdlRendererFlip);
}
