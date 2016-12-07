#include "include/global.hpp"

SurfacePropertiesImpl::SurfacePropertiesImpl()
{

}

SurfacePropertiesImpl::~SurfacePropertiesImpl()
{

}

void SurfacePropertiesImpl::loadAll()
{
    SDL_Log("SurfacePropertiesImpl::loadAll -- loading configuration ...\n");
    loadSurfaces();
}

void SurfacePropertiesImpl::loadSurfaces()
{
    // SpriteProperties -- spriteId, spriteSheetId, sdlRendererFlip, angle
    // EntityProperties -- entityId, defaultOrientation, spriteUp, spriteDown, spriteLeft, spriteRight
    // SurfaceProperties -- EntityProperties, weightValue

    // grass_1
    SpriteProperties grass_1_sprite = { 200, "castle_1", SDL_FLIP_NONE, 0 };
    EntityProperties grass_1_ent = { "grass_1", DOWN, grass_1_sprite, grass_1_sprite, grass_1_sprite, grass_1_sprite };
    SurfaceProperties grass_1_surface = { grass_1_ent, 10 };

    mSurfaceProperties.push_back(grass_1_surface);

    // water_1
    SpriteProperties water_1_sprite = { 100, "castle_1", SDL_FLIP_NONE, 0 };
    EntityProperties water_1_ent = { "water_1", DOWN, water_1_sprite, water_1_sprite, water_1_sprite, water_1_sprite };
    SurfaceProperties water_1_surface = { water_1_ent, 100 };
    mSurfaceProperties.push_back(water_1_surface);
}

std::vector<SurfaceProperties> & SurfacePropertiesImpl::getSurfaceProperties();
{
    return mSurfaceProperties;
}
