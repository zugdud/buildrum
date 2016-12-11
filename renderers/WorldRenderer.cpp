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

void WorldRenderer::renderWorld()
{

    if (mAttached)
    {
        const std::vector<Tile> & tiles = mWorld.getTiles();

        for (size_t tileId = 0; tileId < tiles.size(); tileId++)
        {
            const SDL_Rect tileRect = calcRect(tileId);


            SDL_SetRenderDrawColor(mSDLRenderer, 255, 0, 0, 255);
            SDL_RenderFillRect(mSDLRenderer, &tileRect);

            // if (mCamera.isViewableArea(tileRect))
            // {
            renderTile(tiles[tileId], tileRect);
            // }
        }
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

void WorldRenderer::renderTile(const Tile & tile, const SDL_Rect & tileRect)
{
    const Surface & surface = tile.getSurface();
    const EntityProperties & entityProperties = surface.getSurfaceProperties().entityProperties;
    const EntityOrientation entityOrientation = surface.getEntityOrientation();

    // SDL_Log("WorldRenderer::renderTile -- entityProperties.numLayers: %d \n", entityProperties.numLayers);
    // for (int i = 0; i < entityProperties.numLayers; i++)
    // {

    SDL_Log("WorldRenderer::spriteRect -- entityProperties.numLayers: %d \n", entityProperties.numLayers);

    SpriteProperties spriteProperties = entityProperties.spriteLayers[0].spriteUp;

    switch (entityOrientation)
    {
        case UP: spriteProperties = entityProperties.spriteLayers[0].spriteUp; break;
        case DOWN: spriteProperties = entityProperties.spriteLayers[0].spriteDown; break;
        case LEFT: spriteProperties = entityProperties.spriteLayers[0].spriteLeft; break;
        case RIGHT: spriteProperties = entityProperties.spriteLayers[0].spriteRight; break;
    }

    renderSprite(spriteProperties, tileRect);
    // }
}

void WorldRenderer::renderSprite(const SpriteProperties & spriteProperties, const SDL_Rect & destRect)
{
    SDL_Log("WorldRenderer::spriteRect -- spriteSheetId:  %s spriteId: %d \n", spriteProperties.spriteSheetId.c_str(), spriteProperties.spriteId);

    SDL_Point *center = NULL;
    SDL_Texture *spriteSheetTexture = SpriteSheetManager::Instance().getSpriteSheet(spriteProperties.spriteSheetId).getTexture();
    // const SDL_Rect & spriteRect = SpriteSheetManager::Instance().getSpriteSheet(spriteProperties.spriteSheetId).getSprite(spriteProperties.spriteId).getRect();
    SpriteSheet spriteSheet = SpriteSheetManager::Instance().getSpriteSheet(spriteProperties.spriteSheetId);
    Sprite sprite = spriteSheet.getSprite(spriteProperties.spriteId);
    SDL_Rect rect = sprite.getRect();




    // SDL_Log("WorldRenderer::spriteRect -- rect: [x: %d y: %d w: %d h: %d] \n",
    //         spriteRect.x,
    //         spriteRect.y,
    //         spriteRect.w,
    //         spriteRect.h);

    SDL_RenderCopyEx(mSDLRenderer,
                     spriteSheetTexture,
                     &rect,
                     &destRect,
                     spriteProperties.angle,
                     center,
                     spriteProperties.sdlRendererFlip);
}
