#include "include/global.hpp"

WorldRenderer::WorldRenderer()
{
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
    SDL_Log("WorldRenderer::detatch -- detatched, rendering stopped. \n");
}

void WorldRenderer::renderWorld()
{
    if (mAttached)
    {
        const std::vector<Tile> & tiles = WorldManager::Instance().getWorld().getTiles();
        viewportBackground();
        for (size_t tileId = 0; tileId < tiles.size(); tileId++)
        {
            if (tiles[tileId].isViewableArea())
            {
                // drawTile(tiles[tileId]);
                renderLayers(tiles[tileId]);
                renderActionBar(tiles[tileId], (int) tileId);
                // renderText(tiles[tileId]);
            }
        }

        // TODO move
        TimerManager::Instance().checkTimers();
    }
}

void WorldRenderer::renderActionBar(const Tile & tile, const int & tileId)
{

    if (TimerManager::Instance().isBuilding())
    {
        // SDL_Log("getBuildTileId: %d i: %u icast: %d \n", TimerManager::Instance().getBuildTileId(), i, (int) i);
        if (TimerManager::Instance().getBuildTileId() == tileId)
        {
            const SDL_Rect & tileRect = tile.getRect();
            int hbX = tileRect.x;
            int hbY = tileRect.y;
            int hbW = tileRect.w;
            int hbH = tileRect.h * 0.20;

            int healthBarFillWidth = hbW * TimerManager::Instance().getBuildTimerPercent();

            // x,y,w,h
            SDL_Rect fillRect = { hbX, hbY, healthBarFillWidth, hbH };
            SDL_Rect outlineRect = { hbX, hbY, hbW, hbH };

            // fill
            SDL_SetRenderDrawColor(mSDLRenderer, 0, 255, 0, 255);
            SDL_RenderFillRect(mSDLRenderer, &fillRect);

            // outline
            SDL_SetRenderDrawColor(mSDLRenderer, 0, 0, 0, 255);
            SDL_RenderDrawRect(mSDLRenderer, &outlineRect);
        }
    }

}

// TODO
void WorldRenderer::viewportBackground()
{
    SDL_SetRenderDrawColor(mSDLRenderer, 0, 255, 0, 255);
    SDL_RenderFillRect(mSDLRenderer, &Camera::Instance().getRect());
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
    const std::vector<SpriteProperties> & spriteProperties = tile.getSurface().getSpriteProperties();

    for (size_t i = 0; i < spriteProperties.size(); i++)
    {
        renderSprite(spriteProperties[i], tile.getRect());
    }

    const std::vector<SpriteProperties> & buildableObjectSprites = tile.getBuildableObject().getSpriteProperties();

    for (size_t i = 0; i < buildableObjectSprites.size(); i++)
    {
        renderSprite(buildableObjectSprites[i], tile.getRect());
    }
}
