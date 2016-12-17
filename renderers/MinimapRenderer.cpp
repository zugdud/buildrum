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

    createBGTexture(viewport);
}
//
// void MinimapRenderer::glTexture(const Viewport &viewport)
// {
//     {
//         SDL_Rect clip;
//         void *pixels = nullptr;
//
//         SDL_Rect output_size; // width & height in pixels
//
//         if ( SDL_GetRendererOutputSize(this->renderer(), &output_size.w, &output_size.h) != 0 )
//         {
//             NOM_LOG_ERR(NOM, SDL_GetError() );
//             return Size2i::null;
//         }
//
// // In order to accurately capture our window, with respect to aspect ratio,
// // such as the case of us using device independent scaling [1], we must
// // calculate the true bounding dimensions of our rendering target.
//         clip.x = 0;
//         clip.y = 0;
//         clip.w = output_size.w;
//         clip.h = output_size.h;
//
//         pixels = static_cast<uint32 *> ( malloc(clip.w * clip.h * 4) );
//
//         if ( SDL_RenderReadPixels(this->renderer(),
// // Use calculated bounding dimensions;
// // Pass null to dump the pixels of the entire
// // render target
//                                   &clip,
// // Use the most optimal pixel format;
// // Pass zero here to obtain the pixel format of
// // the render target
// // Either use a filled RenderInfo struct to obtain
// // optimal texture format,
// // ...or... cheat! in the mean time and use this
//                                   SDL_PIXELFORMAT_ARGB8888,
// // Allocated pointer to be filled in with pixels
// // from render target
//                                   pixels,
// // Pitch of our pixels pointer
//                                   clip.w * 4) != 0 )
//         {
//             NOM_LOG_ERR(NOM, SDL_GetError() );
//             return nullptr;
//         }
//
//         int bpp = 0; // bits per pixel
//         uint32 red_mask = 0;
//         uint32 green_mask = 0;
//         uint32 blue_mask = 0;
//         uint32 alpha_mask = 0;
//
//         RendererInfo caps = this->caps(); // Pixel format
//         Image screenshot; // SDL_Surface*
//
// // Width & height of target in pixels
//         SDL_Rect render_size = output_size;
//
//         if ( SDL_BOOL(SDL_PixelFormatEnumToMasks(caps.optimal_texture_format(), &bpp, &red_mask, &green_mask, &blue_mask, &alpha_mask) ) != true )
//         {
//             NOM_LOG_ERR(NOM, SDL_GetError() );
//             return false;
//         }
//
//         screenshot.initialize(pixels, renderer_size.w, renderer_size.h, bpp, (renderer_size.w * 4), red_mask, green_mask, blue_mask, alpha_mask);
//
// // This is a C++ wrapper for ( pixels, width, height, bits_per_pixel, pitch, Rmask, Gmask, Bmask, Amask )
//
// // Note that you may also use SDL_SavePNG & friends here, too!
//         if ( SDL_SaveBMP(screenshot(), "screenshot.bmp") != 0 )
//         {
// // Handle err
//         }
//
// // Success!
// // NOM_LOG_INFO( NOM, "The screen-shot file is saved at: ", filename );
//     }
//
// }

void MinimapRenderer::createBGTexture(const Viewport &viewport)
{
    SDL_Surface *sshot = SDL_CreateRGBSurface(0, viewport.getRect().w, viewport.getRect().h, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);

    if (sshot != NULL)
    {
        if (SDL_RenderReadPixels(mSDLRenderer, NULL, SDL_PIXELFORMAT_ARGB8888, sshot->pixels, sshot->pitch) == 0)
        {
            SDL_Surface *saveSurface = SDL_CreateRGBSurfaceFrom(sshot->pixels, viewport.getRect().w, viewport.getRect().h, 32, sshot->pitch, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
            if (saveSurface != NULL)
            {
                mBackgroundTexture = SDL_CreateTextureFromSurface(mSDLRenderer, saveSurface);
                if (mBackgroundTexture != NULL)
                {
                    SDL_SaveBMP(saveSurface, "winning.bmp");
                }
                else
                {
                    SDL_Log("MinimapRenderer::createBGTexture --  SDL_CreateTextureFromSurface error: %s  \n", SDL_GetError());
                }

                // SDL_FreeSurface(saveSurface);
            }
            else
            {
                SDL_Log("MinimapRenderer::createBGTexture --  SDL_CreateRGBSurfaceFrom error: %s \n", SDL_GetError());
            }
        }
        else
        {
            SDL_Log("MinimapRenderer::createBGTexture -- SDL_RenderReadPixels error: %s \n", SDL_GetError());
        }

        // SDL_FreeSurface(sshot);
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
