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

    mWorld = WorldManager::Instance().getWorld();
    mCamera.configure(viewport, mWorld.getWorldProperties());
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
        const std::vector<Tile> & tiles = mWorld.getTiles();

        for (size_t tileId = 0; tileId < tiles.size(); tileId++)
        {
            const SDL_Rect tileRect = calcRect(tileId);


            if (mCamera.isViewableArea(tileRect))
            {
                drawTile(tiles[tileId], tileRect);
                renderText(tiles[tileId], tileRect);
                // renderLayers(tiles[tileId], tileRect);
            }
        }
    }
}

void WorldRenderer::renderText(const Tile & tile, const SDL_Rect & tileRect)
{
    const TileProperties & tileProperties = tile.getTileProperties();

    std::string tileIdString;
    std::ostringstream convert;

    convert << tileProperties.tileId;
    tileIdString = convert.str();

    FontTextures & fontTextures = FontManager::getInstance()->getTextures(tileProperties.fontProfileName, tileIdString);

    SDL_Texture *labelTexture = fontTextures.getTexture(tileIdString);
    const SDL_Rect & textureSize = fontTextures.getRect(tileIdString);


    SDL_Rect renderRect = { tileRect.x, tileRect.y, textureSize.w, textureSize.h };
    const int heightPadding = (tileRect.h - textureSize.h) / 2;

    renderRect.y = tileRect.y + heightPadding;        // center y axis
    const int widthPadding = (tileRect.w - textureSize.w) / 2;
    renderRect.x = tileRect.x + widthPadding;         // center padding offset

    SDL_RenderCopy(mSDLRenderer, labelTexture, NULL, &renderRect);
}

void WorldRenderer::drawTile(const Tile & tile, const SDL_Rect & tileRect)
{
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

SDL_Rect WorldRenderer::calcRect(const int & tileId)
{
    const int x = mWorld.getWorldProperties().textureSize * (tileId / mWorld.getWorldProperties().rows);
    const int y = mWorld.getWorldProperties().textureSize * (tileId % mWorld.getWorldProperties().rows);
    const int w = mWorld.getWorldProperties().textureSize;
    const int h = mWorld.getWorldProperties().textureSize;

    SDL_Rect rect = { x, y, w, h };

    // SDL_Log("WorldRenderer::calcRect -- tileId: %d rect: [x: %d y: %d w: %d h: %d] \n",
    //         tileId,
    //         rect.x,
    //         rect.y,
    //         rect.w,
    //         rect.h);

    return rect;
}

void WorldRenderer::renderLayers(const Tile & tile, const SDL_Rect & tileRect)
{
    const Surface & surface = tile.getSurface();
    const EntityProperties & entityProperties = surface.getSurfaceProperties().entityProperties;
    const EntityOrientation entityOrientation = surface.getEntityOrientation();

    // SDL_Log("WorldRenderer::renderTile -- entityId: %s numLayers: %d \n",
    //         entityProperties.entityId.c_str(),
    //         entityProperties.numLayers);

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
        renderSprite(spriteProperties, tileRect);
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
