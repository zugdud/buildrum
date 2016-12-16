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

//
// struct WorldProperties
// {
//     std::string worldId;
//     int rows;
//     int columns;
//     int numTiles;
//     int textureSize;
// };

void MinimapRenderer::attach(const Viewport &viewport)
{
    mMinimapRects.clear();

    SDL_Rect borderRect =  { 0, 0, viewport.getRect().w, viewport.getRect().h };

    mBorderRect = borderRect;
    mAttached = true;
    SDL_Log("MinimapRenderer::attach -- attached to viewportId: %s \n", viewport.getViewportProperties().viewportId.c_str());

    const WorldProperties & worldProperties =  WorldManager::Instance().getWorld().getWorldProperties();
    const double tileSize = viewport.getRect().h / worldProperties.rows;

    double percentIncrease = (worldProperties.textureSize - tileSize) / worldProperties.textureSize * 100;
    double percentDecrease = (100 - percentIncrease) / 100;


    SDL_Log("MinimapRenderer::attach -- percentDecrease: %f  \n", percentDecrease);

    const std::vector<Tile> & tiles = WorldManager::Instance().getWorld().getTiles();
    for (size_t tileId = 0; tileId < tiles.size(); tileId++)
    {
        const SDL_Rect tileRect = tiles[tileId].getRect();
        SDL_Rect minimapRect;
        minimapRect.x = ceil(tileRect.x * percentDecrease);
        minimapRect.y = ceil(tileRect.y * percentDecrease);
        minimapRect.w = ceil(tileRect.w * percentDecrease);
        minimapRect.h = ceil(tileRect.h * percentDecrease);
        mMinimapRects.push_back(minimapRect);
    }
}

void MinimapRenderer::detatch()
{
    mAttached = false;
}

void MinimapRenderer::render()
{
    if (mAttached)
    {
        const std::vector<Tile> & tiles = WorldManager::Instance().getWorld().getTiles();
        for (size_t tileId = 0; tileId < tiles.size(); tileId++)
        {
            renderLayers(tiles[tileId], mMinimapRects[tileId]);
        }
        renderBorder();
    }
}

// TODO
void MinimapRenderer::renderBorder()
{
    SDL_SetRenderDrawColor(mSDLRenderer, 0, 255, 0, 255);
    SDL_RenderDrawRect(mSDLRenderer, &mBorderRect);
}

void MinimapRenderer::renderLayers(const Tile & tile, const SDL_Rect & rect)
{
    const std::vector<SpriteProperties> & spriteProperties = tile.getSurface().getSpriteProperties();

    for (size_t i = 0; i < spriteProperties.size(); i++)
    {
        renderSprite(spriteProperties[i], rect);
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
