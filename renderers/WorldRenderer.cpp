#include "include/global.hpp"

WorldRenderer::WorldRenderer()
{
    mSDLRenderer = WindowManager::getInstance()->getSDLRenderer();
    mAttached = false;
}

WorldRenderer::~WorldRenderer()
{

}

const bool & WorldRenderer::isAttached()
{
    return mAttached;
}

void WorldRenderer::attach(const Viewport &viewport)
{
    mAttached = true;
    SDL_Log("WorldRenderer::attach -- attached to viewportId: %s \n", viewport.getViewportProperties().viewportId.c_str());
}

void WorldRenderer::detatch()
{
    mAttached = false;
}

void WorldRenderer::renderWorld()
{

    if (mAttached)
    {
        const std::vector<Tile> & tiles = WorldManager::Instance().getWorld().getTiles();

        for (size_t tileId = 0; tileId < tiles.size(); tileId++)
        {
            if (Camera::Instance().isViewableArea(tiles[tileId].getRect()))
            {
                // drawTile(tiles[tileId]);
                renderLayers(tiles[tileId]);
                renderText(tiles[tileId]);
            }
        }
    }
}

void WorldRenderer::renderText(const Tile & tile)
{
    SDL_Texture *labelTexture = tile.getTextLabel().labelTexture;
    const SDL_Rect & destRect = tile.getTextLabel().rect;

    SDL_RenderCopy(mSDLRenderer, labelTexture, NULL, &destRect);
}

void WorldRenderer::drawTile(const Tile & tile)
{
    const SDL_Rect & tileRect = tile.getRect();
    const TileProperties & tileProperties = tile.getTileProperties();

    if (tileProperties.fillBackground == true)
    {
        SDL_SetRenderDrawColor(mSDLRenderer, tileProperties.backgroundColor.r,
                               tileProperties.backgroundColor.g,
                               tileProperties.backgroundColor.b,
                               tileProperties.backgroundColor.a);
        SDL_RenderFillRect(mSDLRenderer, &tileRect);
    }

    if (tileProperties.drawBorder == true)
    {
        SDL_SetRenderDrawColor(mSDLRenderer, tileProperties.borderColor.r,
                               tileProperties.borderColor.g,
                               tileProperties.borderColor.b,
                               tileProperties.borderColor.a);
        SDL_RenderDrawRect(mSDLRenderer, &tileRect);
    }
}

void WorldRenderer::renderLayers(const Tile & tile)
{
    const Surface & surface = tile.getSurface();
    const EntityProperties & entityProperties = surface.getSurfaceProperties().entityProperties;
    const EntityOrientation entityOrientation = surface.getEntityOrientation();

    for (int i = 0; i < entityProperties.numLayers; i++)
    {
        SpriteProperties spriteProperties = entityProperties.spriteLayers[i].spriteUp;

        switch (entityOrientation)
        {
            case UP: spriteProperties = entityProperties.spriteLayers[i].spriteUp; break;
            case DOWN: spriteProperties = entityProperties.spriteLayers[i].spriteDown; break;
            case LEFT: spriteProperties = entityProperties.spriteLayers[i].spriteLeft; break;
            case RIGHT: spriteProperties = entityProperties.spriteLayers[i].spriteRight; break;
        }
        renderSprite(spriteProperties, tile.getRect());
    }
}

void WorldRenderer::renderSprite(const SpriteProperties & spriteProperties, const SDL_Rect & destRect)
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
