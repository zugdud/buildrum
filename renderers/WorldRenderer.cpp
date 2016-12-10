#include "include/global.hpp"

WorldRenderer::WorldRenderer()
{
    mSDLRenderer = WindowManager::getInstance()->getSDLRenderer();
}

WorldRenderer::~WorldRenderer()
{

}

void WorldRenderer::renderWorld()
{
    const std::vector<Tile> & tiles =  World::getTiles();
    for (size_t i = 0; i < tiles.size(); i++)
    {
        renderTile(tile[i]);
    }
}

void WorldRenderer::renderTile(const Tile & tile)
{
    const Surface & surface = getSurface();
    const EntityProperties & entityProperties = surface.getSurfaceProperties().entityProperties;
    const EntityOrientation entityOrientation = surface.getEntityOrientation();

    for (int i = 0; i < entityProperties.numLayers; i++)
    {
        switch (entityOrientation)
        {
            case UP: renderSprite(entityProperties.spriteLayers[i].spriteUp); break;
            case DOWN: renderSprite(entityProperties.spriteLayers[i].spriteDown); break;
            case LEFT: renderSprite(entityProperties.spriteLayers[i].spriteLeft); break;
            case RIGHT: renderSprite(entityProperties.spriteLayers[i].spriteRight); break;
        }
    }
}

void WorldRenderer::renderSprite(const SpriteProperties & spriteProperties)
{
    const int center = 0;
    const int textureSize = mWorld.getWorldProperties().textureSize;
    SDL_Texture *spriteSheetTexture = SpriteSheetManager::Instance().getSpriteSheet(spriteProperties.spriteSheetId).getTexture();
    const SDL_Rect & spriteRect = SpriteSheetManager::Instance().getSpriteSheet(spriteProperties.spriteSheetId).getSprite(spriteProperties.spriteId).getRect();

    SDL_RenderCopyEx(mSDLRenderer, spriteSheetTexture, &spriteRect, &destRect, spriteProperties.angle, center, spriteProperties.sdlRendererFlip);
}
