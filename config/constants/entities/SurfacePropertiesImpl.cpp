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

    // SpriteLayer -- entityId, spriteUp, spriteDown, spriteLeft, spriteRight
    // SpriteProperties -- spriteId, spriteSheetId, sdlRendererFlip, angle

    // EntityProperties -- entityId, defaultOrientation
    // SurfaceProperties -- EntityProperties, weightValue



    // grass_1
    SpriteProperties grass_1_sprite = { 200, "castle_1", SDL_FLIP_NONE, 0 };
    SpriteLayer grass_1_layer = { grass_1_sprite, grass_1_sprite, grass_1_sprite, grass_1_sprite };

    EntityProperties grass_1_ent = { "grass_1", DOWN };
    SurfaceProperties grass_1_surface;

    grass_1_surface.entityProperties =  grass_1_ent;
    grass_1_surface.weightValue = 10;
    grass_1_surface.numLayers = 1;
    grass_1_surface.spriteLayers[0] = grass_1_layer;

    mSurfaceProperties["grass_1"] = grass_1_surface;

    // water_1
    SpriteProperties water_1_sprite = { 200, "castle_1", SDL_FLIP_NONE, 0 };
    SpriteLayer water_1_layer = { water_1_sprite, water_1_sprite, water_1_sprite, water_1_sprite };

    EntityProperties water_1_ent = { "water_1", DOWN };
    SurfaceProperties water_1_surface;

    water_1_surface.entityProperties =  water_1_ent;
    water_1_surface.weightValue = 100;
    water_1_surface.numLayers = 1;
    water_1_surface.spriteLayers[0] = water_1_ent;

    mSurfaceProperties["water_1"] = water_1_surface;
}

const SurfaceProperties &  SurfacePropertiesImpl::getSurfaceProperties(const std::string entityId)
{
    return mSurfaceProperties[entityId];
}
