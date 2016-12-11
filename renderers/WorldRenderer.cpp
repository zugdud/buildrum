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

void WorldRenderer::attach(const Viewport &viewport)
{

    // (const CameraProperties &CameraProperties, const Viewport & viewport, const WorldProperties & worldProperties);
    mWorld = WorldManager::Instance().getWorld();
    mCamera.configure(viewport, mWorld.getWorldProperties());
    mAttached = true;
    SDL_Log("WorldRenderer::attach -- attached to viewportId: %s \n", viewport.getViewportProperties().viewportId.c_str());
}

void WorldRenderer::detatch()
{
    mAttached = false;
}

void WorldRenderer::render()
{
    if (mAttached)
    {
        const std::vector<Tile> & tiles = mWorld.getTiles();

        for (size_t tileId = 0; tileId < tiles.size(); tileId++)
        {
            const SDL_Rect tileRect = calcRect(tileId);
            if (mCamera.isViewableArea(tileRect))
            {
                renderTile(tiles[tileId], tileRect);
            }
        }
    }
}

SDL_Rect WorldRenderer::calcRect(const int & tileId)
{
    const int x = tileId / mWorld.getWorldProperties().rows;
    const int y = tileId % mWorld.getWorldProperties().rows;
    const int w = mWorld.getWorldProperties().textureSize;
    const int h = mWorld.getWorldProperties().textureSize;

    SDL_Rect rect = { x, y, w, h };

    return rect;
}

void WorldRenderer::renderTile(const Tile & tile, const SDL_Rect & tileRect)
{
    const Surface & surface = tile.getSurface();
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
