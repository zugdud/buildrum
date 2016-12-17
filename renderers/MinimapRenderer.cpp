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


    std::string filePath = "testamundo.bmp";
    saveScreenshotBMP(filePath, WindowManager::getInstance()->getWindow().getSDLWindow(), mSDLRenderer);

}

bool MinimapRenderer::saveScreenshotBMP(std::string filepath, SDL_Window *SDLWindow, SDL_Renderer *SDLRenderer)
{
    SDL_Surface *saveSurface = NULL;
    SDL_Surface *infoSurface = NULL;

    infoSurface = SDL_GetWindowSurface(SDLWindow);
    if (infoSurface == NULL)
    {
        SDL_Log("MinimapRenderer::saveScreenshotBMP -- Failed to create info surface from window in saveScreenshotBMP(string), SDL_GetError(): %s \n", SDL_GetError());
    }
    else
    {
        unsigned char *pixels = new (std::nothrow) unsigned char[infoSurface->w * infoSurface->h * infoSurface->format->BytesPerPixel];
        if (pixels == 0)
        {
            SDL_Log("MinimapRenderer::saveScreenshotBMP -- Unable to allocate memory for screenshot pixel data buffer! \n");
            return false;
        }
        else
        {
            if (SDL_RenderReadPixels(SDLRenderer, &infoSurface->clip_rect, infoSurface->format->format, pixels, infoSurface->w * infoSurface->format->BytesPerPixel) != 0)
            {
                SDL_Log("MinimapRenderer::saveScreenshotBMP -- Failed to read pixel data from SDL_Renderer object. SDL_GetError(): %s \n", SDL_GetError());
                pixels = NULL;
                return false;
            }
            else
            {
                saveSurface = SDL_CreateRGBSurfaceFrom(pixels, infoSurface->w, infoSurface->h, infoSurface->format->BitsPerPixel, infoSurface->w * infoSurface->format->BytesPerPixel, infoSurface->format->Rmask, infoSurface->format->Gmask, infoSurface->format->Bmask, infoSurface->format->Amask);
                if (saveSurface == NULL)
                {
                    SDL_Log("MinimapRenderer::saveScreenshotBMP -- Couldn't create SDL_Surface from renderer pixel data. SDL_GetError(): %s \n", SDL_GetError());
                    return false;
                }
                mBackgroundTexture = SDL_CreateTextureFromSurface(SDLRenderer, saveSurface);
                SDL_SaveBMP(saveSurface, filepath.c_str());
                SDL_FreeSurface(saveSurface);
                saveSurface = NULL;
            }
            delete[] pixels;
        }
        SDL_FreeSurface(infoSurface);
        infoSurface = NULL;
    }
    return true;
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

// TODO
void MinimapRenderer::renderBorder()
{
    SDL_SetRenderDrawColor(mSDLRenderer, 0, 255, 0, 255);
    SDL_RenderDrawRect(mSDLRenderer, &mBorderRect);
}

void MinimapRenderer::renderCamera()
{
    SDL_Rect scaledRect;

    scaledRect.x = (Camera::Instance().getRect().x * mScaleRatio) + 2;
    scaledRect.y = (Camera::Instance().getRect().y * mScaleRatio) + 2;
    scaledRect.w = (Camera::Instance().getRect().w * mScaleRatio) - 2;
    scaledRect.h = (Camera::Instance().getRect().h * mScaleRatio) - 2;

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
