#include "include/global.hpp"

MinimapRenderer::MinimapRenderer()
{
    mSDLRenderer = WindowManager::getInstance()->getSDLRenderer();
    mAttached = false;
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
    SDL_Log("MinimapRenderer::attach -- attached to viewportId: %s \n", viewport.getViewportProperties().viewportId.c_str());
}

void MinimapRenderer::detatch()
{
    mAttached = false;
}

void MinimapRenderer::render()
{
    if (mAttached)
    {
        viewportBackground();
        const std::vector<Tile> & tiles = WorldManager::Instance().getWorld().getTiles();
        for (size_t tileId = 0; tileId < tiles.size(); tileId++)
        {
            if (tiles[tileId].isViewableArea())
            {
                renderLayers(tiles[tileId]);
            }
        }
        // SDL_Log("Render count: %d \n", renderCount);
    }
}

// TODO
void MinimapRenderer::viewportBackground()
{
    SDL_Rect bgRect = { 0, 0, 2000, 2000 };

    SDL_SetRenderDrawColor(mSDLRenderer, 0, 255, 0, 255);
    SDL_RenderFillRect(mSDLRenderer, &bgRect);
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
