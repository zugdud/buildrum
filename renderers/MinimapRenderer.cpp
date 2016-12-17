#include "include/global.hpp"

MinimapRenderer::MinimapRenderer()
{
    mSDLRenderer = WindowManager::getInstance()->getSDLRenderer();
    mAttached = false;
    mScaleRatio = 1.0;
}

MinimapRenderer::~MinimapRenderer()
{

}

const bool & MinimapRenderer::isAttached()
{
    return mAttached;
}

//
// struct WorldProperties
// {
//     std::string worldId;
//     int rows;
//     int columns;
//     int numTiles;
//     int textureSize;
// };

void MinimapRenderer::attach(const Viewport &viewport)
{
    mMinimapRects.clear();
    SDL_Rect borderRect =  { 0, 0, viewport.getRect().w, viewport.getRect().h };
    mBorderRect = borderRect;
    mAttached = true;

    SDL_Log("MinimapRenderer::attached -- creating background texture ... \n");
    createBackgroundTexture(viewport);

}

void MinimapRenderer::createBackgroundTexture(const Viewport &viewport)
{
    const WorldProperties & worldProperties =  WorldManager::Instance().getWorld().getWorldProperties();
    const double tileSize = viewport.getRect().h / worldProperties.rows;
    const double percentDecrease = (worldProperties.textureSize - tileSize) / worldProperties.textureSize * 100;

    mScaleRatio = (100 - percentDecrease) / 100;

    const std::vector<Tile> & tiles = WorldManager::Instance().getWorld().getTiles();

    for (size_t tileId = 0; tileId < tiles.size(); tileId++)
    {
        const SDL_Rect tileRect = tiles[tileId].getRect();
        SDL_Rect minimapRect;
        minimapRect.x = ceil(tileRect.x * mScaleRatio);
        minimapRect.y = ceil(tileRect.y * mScaleRatio);
        minimapRect.w = ceil(tileRect.w * mScaleRatio);
        minimapRect.h = ceil(tileRect.h * mScaleRatio);
        mMinimapRects.push_back(minimapRect);
    }

    for (size_t tileId = 0; tileId < tiles.size(); tileId++)
    {
        renderLayers(tiles[tileId], mMinimapRects[tileId]);
    }

    SDL_Surface *sshot = SDL_CreateRGBSurface(0, mBorderRect.w, mBorderRect.h, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
    SDL_RenderReadPixels(mSDLRenderer, NULL, SDL_PIXELFORMAT_ARGB8888, sshot->pixels, sshot->pitch);
    mBackgroundTexture = SDL_CreateTextureFromSurface(mSDLRenderer, sshot);
    SDL_SaveBMP(sshot, "screenshot.bmp");
    SDL_FreeSurface(sshot);
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
        renderCamera();
        renderBorder();
    }
}

// TODO
void MinimapRenderer::renderBorder()
{
    SDL_SetRenderDrawColor(mSDLRenderer, 0, 255, 0, 255);
    SDL_RenderDrawRect(mSDLRenderer, &mBorderRect);
}

void MinimapRenderer::renderCamera()
{
    SDL_Rect scaledRect;

    scaledRect.x = Camera::Instance().getRect().x * mScaleRatio;
    scaledRect.y = Camera::Instance().getRect().y * mScaleRatio;
    scaledRect.w = Camera::Instance().getRect().w * mScaleRatio;
    scaledRect.h = Camera::Instance().getRect().h * mScaleRatio;

    scaledRect.w = scaledRect.w / Camera::Instance().getZoomFactor();
    scaledRect.h = scaledRect.h / Camera::Instance().getZoomFactor();
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
