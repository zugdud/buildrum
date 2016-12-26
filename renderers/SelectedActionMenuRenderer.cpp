#include "include/global.hpp"

SelectedActionMenuRenderer::SelectedActionMenuRenderer()
{
    mSDLRenderer = WindowManager::getInstance()->getSDLRenderer();
}

SelectedActionMenuRenderer::~SelectedActionMenuRenderer()
{

}

const bool & SelectedActionMenuRenderer::isAttached()
{
    return mAttached;
}

void SelectedActionMenuRenderer::attach(const Viewport &viewport)
{
    mAttached = true;

    SDL_Rect borderRect = { 0, 0, viewport.getRect().w, viewport.getRect().h };
    mBorder = borderRect;

    SDL_Log("----------------------------------------------------\n");
    SDL_Log("SelectedActionMenuRenderer::attached -- setting up ... \n");
    SDL_Log("----------------------------------------------------\n");
}

void SelectedActionMenuRenderer::detatch()
{
    mAttached = false;
    SDL_Log("SelectedActionMenuRenderer::detatch -- detatched, rendering stopped. \n");
}

void SelectedActionMenuRenderer::render()
{
    if (mAttached)
    {
        renderBorder();
        renderBackground();
    }
}

// TODO configs
void SelectedActionMenuRenderer::renderBorder()
{
    SDL_SetRenderDrawColor(mSDLRenderer, 0, 255, 0, 255);
    SDL_RenderDrawRect(mSDLRenderer, &mBorder);
}

void SelectedActionMenuRenderer::renderBackground()
{
    SDL_SetRenderDrawColor(mSDLRenderer, 0, 0, 255, 255);
    SDL_RenderFillRect(mSDLRenderer, &mBorder);
}

void SelectedActionMenuRenderer::renderSprite(const SpriteProperties & spriteProperties, const SDL_Rect & destRect)
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
