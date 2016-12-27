#include "include/global.hpp"

StatusMenuRenderer::StatusMenuRenderer()
{
    mSDLRenderer = WindowManager::getInstance()->getSDLRenderer();
}

StatusMenuRenderer::~StatusMenuRenderer()
{

}

const bool & StatusMenuRenderer::isAttached()
{
    return mAttached;
}

void StatusMenuRenderer::attach(const Viewport &viewport)
{
    mAttached = true;

    SDL_Rect borderRect = { 0, 0, viewport.getRect().w, viewport.getRect().h };
    mBorder = borderRect;

    SDL_Log("----------------------------------------------------\n");
    SDL_Log("StatusMenuRenderer::attached -- setting up ... \n");
    SDL_Log("----------------------------------------------------\n");
}

void StatusMenuRenderer::detatch()
{
    mAttached = false;
    SDL_Log("StatusMenuRenderer::detatch -- detatched, rendering stopped. \n");
}

void StatusMenuRenderer::render()
{
    if (mAttached)
    {
        renderBackground();
        renderBorder();
    }
}

// TODO configs
void StatusMenuRenderer::renderBorder()
{
    SDL_SetRenderDrawColor(mSDLRenderer, 0, 255, 0, 255);
    SDL_RenderDrawRect(mSDLRenderer, &mBorder);
}

void StatusMenuRenderer::renderBackground()
{
    SDL_SetRenderDrawColor(mSDLRenderer, 0, 255, 0, 255);
    SDL_RenderFillRect(mSDLRenderer, &mBorder);
}

void StatusMenuRenderer::renderSprite(const SpriteProperties & spriteProperties, const SDL_Rect & destRect)
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
