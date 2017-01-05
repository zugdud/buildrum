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
