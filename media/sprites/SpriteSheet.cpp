#include "config/include.h"

SpriteSheet::SpriteSheet()
{

}

SpriteSheet::~SpriteSheet()
{

}

SpriteSheet::configure()
{

}

// the spriteId value
void SpriteSheet::setSprites(const int & spriteId)
{

}

// std::string spriteSheetId;
// int rows;
// int columns;
// int spriteSize;
// int spriteCount;
// int sheetPixelWidth;
// int sheetPixelHeight;
// int pitch
// std::string fileName;

void SpriteSheet::setSprites(const int & spriteId)
{
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
            const pixelX = (offsetX * mSpriteSheetProperties.spriteSize); // pixel x position of the sprite
            const pixelY = (offsetY * mSpriteSheetProperties.spriteSize); // pixel y position of the sprite

            SDL_Rect spriteRect = { pixelX, pixelY, mSpriteSheetProperties.spriteSize, mSpriteSheetProperties.spriteSize };

            mSprites.push_back(Sprite(spriteId, linearIndex, spriteRect));
            linearIndex++; // spriteSheet index
            spriteId++; // global index
        }
    }
}

bool SpriteSheet::loadSpriteSheet()
{
    SDL_Texture *newTexture = NULL;
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

            newTexture = SDL_CreateTexture(mWindowRenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, formattedSurface->w, formattedSurface->h);
            if ( newTexture == NULL )
            {
                SDL_Log("SpriteSheet::loadSpriteSheet -- Unable to create blank texture, SDL error: %s", SDL_GetError());
            }
            else
            {
                setTransparency(SDL_Texture * newTexture, SDL_Surface * formattedSurface);
                SDL_UnlockTexture(newTexture);
            }

            SDL_FreeSurface(formattedSurface);
        }

        SDL_FreeSurface(loadedSurface);
    }


    if (newTexture != NULL)
    {
        return true;
    }
    else
    {
        SDL_Log("SpriteSheet::loadSpriteSheet -- ERROR: mSpriteSheetId %s", SDL_GetError());
        return false;
    }
}

void SpriteSheet::setTransparency(SDL_Texture *newTexture, SDL_Surface *formattedSurface)
{
    void *pixels;

    SDL_SetTextureBlendMode(newTexture, SDL_BLENDMODE_BLEND);
    SDL_LockTexture(newTexture, &formattedSurface->clip_rect, &pixels, &pixels);

    memcpy(pixels, formattedSurface->pixels, formattedSurface->pitch * formattedSurface->h);

    Uint32 *pixels = (Uint32 *) pixels;
    int pixelCount = ( mSpriteSheetProperties.pitch / 4 ) * formattedSurface->h;

    Uint32 colorKey = SDL_MapRGB(formattedSurface->format, 0, 0xFF, 0xFF);
    Uint32 transparent = SDL_MapRGBA(formattedSurface->format, 0x00, 0xFF, 0xFF, 0x00);

    for (int i = 0; i < pixelCount; ++i)
    {
        if (pixels[i] == colorKey)
        {
            pixels[i] = transparent;
        }
    }
}
