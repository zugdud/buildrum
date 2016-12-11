#include "include/global.hpp"

WorldRenderer::WorldRenderer()
{
    mSDLRenderer = WindowManager::getInstance()->getSDLRenderer();
    mAttached = false;
}

WorldRenderer::~WorldRenderer()
{

}

void attachToWorld()
{

}
void removeFromWorld()
{

}

void WorldRenderer::attach(const ViewportProperties &viewportProperties)
{
    mWorldProperties = World::getInstance().getWorldProperties();
    mCamera.configure(viewportProperties, mWorldProperties);
    mAttached = true;
    SDL_Log("WorldRenderer::attach -- attached to viewportId: %s \n", viewportProperties.viewportId);
}

void WorldRenderer::detatch()
{
    mAttached = false;
}

void WorldRenderer::updateConfig()
{

}

void WorldRenderer::render();
{
    if (mAttached)
    {
        const std::vector<Tile> & tiles = World::getInstance()->getTiles();

        for (size_t i = 0; i < tiles.size(); i++)
        {
            const SDL_Rect tileRect = calcRect(tileId);
            if (mCamera.isViewableArea(tileRect))
            {
                renderTile(tile[i], tileRect);
            }
        }
    }
}

SDL_Rect WorldRenderer::calcRect(const int & tileId)
{
    const int w = mWorldProperties.textureSize;
    const int h = mWorldProperties.textureSize;
    const int x = tileId / mWorldProperties.rows;
    const int y = tileId %  mWorldProperties.rows;

    SDL_Rect rect = { x, y, w, h };

    return rect;
}

void WorldRenderer::renderTile(const Tile & tile, const SDL_Rect & tileRect)
{
    const Surface & surface = getSurface();
    const EntityProperties & entityProperties = surface.getSurfaceProperties().entityProperties;
    const EntityOrientation entityOrientation = surface.getEntityOrientation();

    SpriteProperties spriteProperties;

    for (int i = 0; i < entityProperties.numLayers; i++)
    {
        switch (entityOrientation)
        {
            case UP: spriteProperties = entityProperties.spriteLayers[i].spriteUp; break;
            case DOWN: spriteProperties = entityProperties.spriteLayers[i].spriteDown; break;
            case LEFT: spriteProperties = entityProperties.spriteLayers[i].spriteLeft; break;
            case RIGHT: spriteProperties = entityProperties.spriteLayers[i].spriteRight; break;
        }
    }
    renderSprite(spriteProperties, tileRect);
}

void WorldRenderer::renderSprite(const SpriteProperties & spriteProperties, const SDL_Rect & destRect)
{
    const int center = 0;
    const int textureSize = mWorldProperties.textureSize;
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
