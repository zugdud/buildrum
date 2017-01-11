#include "include/global.hpp"

BaseRenderer::BaseRenderer()
{
    mSDLRenderer = WindowManager::getInstance()->getSDLRenderer();
}
BaseRenderer::~BaseRenderer()
{

}

void BaseRenderer::renderSprite(const SpriteProperties & spriteProperties, const SDL_Rect & destRect)
{
    SDL_Point *center = NULL;
    SpriteSheet *spriteSheet = SpriteSheetManager::Instance().getSpriteSheet(spriteProperties.spriteSheetId);

    if (spriteSheet != NULL)
    {
        SDL_Texture *spriteSheetTexture = spriteSheet->getTexture();
        const SDL_Rect & spriteRect = spriteSheet->getSprite(spriteProperties.spriteId).getRect();

        SDL_RenderCopyEx(mSDLRenderer,
                         spriteSheetTexture,
                         &spriteRect,
                         &destRect,
                         spriteProperties.angle,
                         center,
                         spriteProperties.sdlRendererFlip);
    }
}

void BaseRenderer::renderString(const std::string & text, const std::string & fontProfile, const SDL_Rect & cellRect)
{

    FontTextures & fontTextures = FontManager::getInstance()->getTextures(fontProfile, text);

    SDL_Texture *labelTexture = fontTextures.getTexture(text);
    const SDL_Rect & textureSize = fontTextures.getRect(text);

    SDL_Rect renderRect = { cellRect.x, cellRect.y, textureSize.w, textureSize.h };
    const int heightPadding = (cellRect.h - textureSize.h) / 2;

    renderRect.y = cellRect.y + heightPadding;        // center y axis

    const int widthPadding = (cellRect.w - textureSize.w) / 2;
    renderRect.x = cellRect.x + widthPadding;         // center padding offset

    SDL_RenderCopy(mSDLRenderer, labelTexture, NULL, &renderRect);
}
