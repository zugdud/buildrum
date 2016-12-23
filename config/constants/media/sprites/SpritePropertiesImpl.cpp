#include "include/global.hpp"

SpritePropertiesImpl::SpritePropertiesImpl()
{

}

SpritePropertiesImpl::~SpritePropertiesImpl()
{

}

void SpritePropertiesImpl::loadAll()
{
    SDL_Log("SpritePropertiesImpl::loadAll -- loading configuration ...\n");
    setCastle_1();
    setCastle_2();
}

void SpritePropertiesImpl::setCastle_2()
{
    mSpriteProperties["water_1"] = (192, "castle_2", SDL_FLIP_NONE, 0);
    mSpriteProperties["banner_1"] = (96, "castle_2", SDL_FLIP_NONE, 0);
    mSpriteProperties["banner_2"] = (112, "castle_2", SDL_FLIP_NONE, 0);
    mSpriteProperties["emblem_1"] = (99, "castle_2", SDL_FLIP_NONE, 0);
    mSpriteProperties["emblem_2"] = (115, "castle_2", SDL_FLIP_NONE, 0);
    mSpriteProperties["spire_1"] = (128, "castle_2", SDL_FLIP_NONE, 0);
    mSpriteProperties["ladder_1"] = (146, "castle_2", SDL_FLIP_NONE, 0);
}

void SpritePropertiesImpl::setCastle_1()
{
    mSpriteProperties["brick_1"] = (24, "castle_1", SDL_FLIP_NONE, 0);
    mSpriteProperties["brick_2"] = (65, "castle_1", SDL_FLIP_NONE, 0);
    mSpriteProperties["field_1"] = (195, "castle_1", SDL_FLIP_NONE, 0);
    mSpriteProperties["field_2"] = (196, "castle_1", SDL_FLIP_NONE, 0);
    mSpriteProperties["field_3"] = (213, "castle_1", SDL_FLIP_NONE, 0);

    mSpriteProperties["anvil_1"] = (133, "castle_1", SDL_FLIP_NONE, 0);
    mSpriteProperties["anvil_2"] = (149, "castle_1", SDL_FLIP_NONE, 0);
    mSpriteProperties["latern_1"] = (100, "castle_1", SDL_FLIP_NONE, 0);
    mSpriteProperties["latern_2"] = (116, "castle_1", SDL_FLIP_NONE, 0);
    mSpriteProperties["crate_1"] = (129, "castle_1", SDL_FLIP_NONE, 0);
    mSpriteProperties["crate_2"] = (131, "castle_1", SDL_FLIP_NONE, 0);
    mSpriteProperties["crate_3"] = (134, "castle_1", SDL_FLIP_NONE, 0);
    mSpriteProperties["crate_4"] = (150, "castle_1", SDL_FLIP_NONE, 0);
    mSpriteProperties["crate_5"] = (234, "castle_1", SDL_FLIP_NONE, 0);
    mSpriteProperties["barrel_1"] = (233, "castle_1", SDL_FLIP_NONE, 0);
}

SpriteProperties SpritePropertiesImpl::getSpriteProperties(
    const int & spriteId,
    const std::string & spriteSheetId,
    const SDL_RendererFlip & sdlRendererFlip,
    const double & angle,
    )
{

    SpriteProperties spriteProperties;

    spriteProperties.spriteId = spriteId;
    spriteProperties.spriteSheetId = spriteSheetId;
    spriteProperties.sdlRendererFlip = sdlRendererFlip;
    spriteProperties.angle = angle;

    return spriteProperties;
}

const SpriteProperties & SpritePropertiesImpl::getSpriteProperties(const std::string & spriteName)
{
    return mSpriteProperties[spriteName]
}
