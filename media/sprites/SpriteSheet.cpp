#include "include/global.hpp"

SpriteSheet::SpriteSheet()
{
    mTexture = NULL;
    mSDLRenderer = WindowManager::getInstance()->getSDLRenderer();
}

SpriteSheet::~SpriteSheet()
{

}

bool SpriteSheet::configure(const EnvironmentMediaPropertiesImpl &environmentMediaPropertiesImpl,
                            const SpriteSheetProperties &spriteSheetProperties)
{
    mEnvironmentMediaPropertiesImpl = environmentMediaPropertiesImpl;
    mSpriteSheetProperties = spriteSheetProperties;
    SDL_Log("---------------------------------------------------- \n");
    SDL_Log("SpriteSheet::configure -- spriteSheetId: %s \n", mSpriteSheetProperties.spriteSheetId.c_str());
    bool success = loadSpriteSheet();
    setSprites();
    SDL_Log("---------------------------------------------------- \n");
    return success;
}

// struct SpriteSheetProperties
// {
//     std::string spriteSheetId;
//     std::string fileName;
//     int rows;
//     int columns;
//     int spriteSize;
//     int spriteCount;
//     int sheetPixelWidth;
//     int sheetPixelHeight;
//     SDL_Color colorKey;
// };

void SpriteSheet::setSprites()
{
    SDL_Log("SpriteSheet::setSprites -- setting sprites, spriteSheetId: %s \n", mSpriteSheetProperties.spriteSheetId.c_str());

    const int xSprites = (mSpriteSheetProperties.sheetPixelWidth / mSpriteSheetProperties.spriteSize); // num sprites in X axis
    const int ySprites = (mSpriteSheetProperties.sheetPixelHeight / mSpriteSheetProperties.spriteSize); // num sprites in Y axis
    int pixelX = 0;  // pixel position in the texture
    int pixelY = 0;  // pixel position in the texutre
    int linearIndex = 0;

    // traverse the texture
    for (int offsetY = 0; offsetY < ySprites; offsetY++)
    {
        for (int offsetX = 0; offsetX < xSprites; offsetX++)
        {
            pixelX = (offsetX * mSpriteSheetProperties.spriteSize);  // pixel x position of the sprite
            pixelY = (offsetY * mSpriteSheetProperties.spriteSize);  // pixel y position of the sprite

            SDL_Rect spriteRect = { pixelX, pixelY, mSpriteSheetProperties.spriteSize, mSpriteSheetProperties.spriteSize };

            // SDL_Log("SpriteSheet::setSprites -- spriteSheetId: %s spriteId: %d spriteRect: [x: %d y: %d w: %d h: %d] \n",
            //         mSpriteSheetProperties.spriteSheetId.c_str(),
            //         linearIndex,
            //         spriteRect.x,
            //         spriteRect.y,
            //         spriteRect.w,
            //         spriteRect.h);

            mSprites.push_back(Sprite(linearIndex, spriteRect));
            linearIndex++; // spriteSheet index

        }
    }
    SDL_Log("SpriteSheet::setSprites -- set sprites count: %d \n", linearIndex);
}

bool SpriteSheet::loadSpriteSheet()
{
    const std::string filePath = mEnvironmentMediaPropertiesImpl.getEnvironmentMediaProperties().spriteSheetDirPath + mSpriteSheetProperties.fileName;

    SDL_Log("SpriteSheet::loadSpriteSheet -- loading spriteSheet from file, spriteSheetId: %s filePath: %s \n",
            mSpriteSheetProperties.spriteSheetId.c_str(),
            filePath.c_str());

    mTexture = NULL;
    SDL_Surface *loadedSurface = IMG_Load(filePath.c_str() );

    if ( loadedSurface == NULL )
    {
        SDL_Log("SpriteSheet::loadSpriteSheet -- Unable to load image, SDL error: %s", SDL_GetError());
    }
    else
    {
        SDL_Surface *formattedSurface = SDL_ConvertSurfaceFormat(loadedSurface, SDL_PIXELFORMAT_RGBA8888, 0);
        if ( formattedSurface == NULL )
        {
            SDL_Log("SpriteSheet::loadSpriteSheet -- Unable to convert loaded surface to display format, SDL error: %s", SDL_GetError());
        }
        else
        {

            mTexture = SDL_CreateTexture(mSDLRenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, formattedSurface->w, formattedSurface->h);
            if ( mTexture == NULL )
            {
                SDL_Log("SpriteSheet::loadSpriteSheet -- Unable to create blank texture, SDL error: %s", SDL_GetError());
            }
            else
            {
                // applyTransparency(mTexture, formattedSurface);
            }

            SDL_FreeSurface(formattedSurface);
        }

        SDL_FreeSurface(loadedSurface);
    }


    if (mTexture != NULL)
    {
        return true;
    }
    else
    {
        SDL_Log("SpriteSheet::loadSpriteSheet -- ERROR: mSpriteSheetId %s", SDL_GetError());
        return false;
    }
}

void SpriteSheet::applyTransparency(SDL_Texture *newTexture, SDL_Surface *formattedSurface)
{
    int pitch;
    void *getPixels;

    SDL_SetTextureBlendMode(newTexture, SDL_BLENDMODE_BLEND);
    SDL_LockTexture(newTexture, &formattedSurface->clip_rect, &getPixels, &pitch);

    memcpy(getPixels, formattedSurface->pixels, formattedSurface->pitch * formattedSurface->h);

    Uint32 *pixels = (Uint32 *) getPixels;
    int pixelCount = ( pitch / 4 ) * formattedSurface->h;

    Uint32 colorKey = SDL_MapRGB(formattedSurface->format,
                                 mSpriteSheetProperties.colorKey.r,
                                 mSpriteSheetProperties.colorKey.g,
                                 mSpriteSheetProperties.colorKey.b);
    Uint32 transparent = SDL_MapRGBA(formattedSurface->format,
                                     mSpriteSheetProperties.colorKey.r,
                                     mSpriteSheetProperties.colorKey.g,
                                     mSpriteSheetProperties.colorKey.b,
                                     mSpriteSheetProperties.colorKey.a);

    for (int i = 0; i < pixelCount; ++i)
    {
        if (pixels[i] == colorKey)
        {
            pixels[i] = transparent;
        }
    }
    SDL_UnlockTexture(newTexture);
}

SDL_Texture * SpriteSheet::getTexture() const
{
    return mTexture;
}
const Sprite & SpriteSheet::getSprite(const int & spriteId) const
{
    SDL_Log("SpriteSheet::getSprite -- spriteId: %d size: %zu \n", spriteId, mSprites.size());
    return mSprites[spriteId];
}
