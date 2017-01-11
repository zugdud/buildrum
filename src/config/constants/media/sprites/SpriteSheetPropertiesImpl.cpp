#include "include/global.hpp"

SpriteSheetPropertiesImpl::SpriteSheetPropertiesImpl()
{

}

SpriteSheetPropertiesImpl::~SpriteSheetPropertiesImpl()
{

}

void SpriteSheetPropertiesImpl::loadAll()
{
    SDL_Log("SpriteSheetPropertiesImpl::loadAll -- loading configuration ...\n");
    setSpriteSheetProperties();
}

void SpriteSheetPropertiesImpl::setSpriteSheetProperties()
{
    SDL_Color transparent = { 0, 255, 255, 0 };

    SpriteSheetProperties castle_1;

    castle_1.spriteSheetId = "castle_1";
    castle_1.fileName = "castle_1.png";
    castle_1.rows = 16;
    castle_1.columns = 16;
    castle_1.spriteSize = 32;
    castle_1.spriteCount = 256;
    castle_1.sheetPixelWidth = 512;
    castle_1.sheetPixelHeight = 512;
    castle_1.colorKey = transparent;

    SpriteSheetProperties castle_2;

    castle_2.spriteSheetId = "castle_2";
    castle_2.fileName = "castle_2.png";
    castle_2.rows = 16;
    castle_2.columns = 16;
    castle_2.spriteSize = 32;
    castle_2.spriteCount = 256;
    castle_2.sheetPixelWidth = 512;
    castle_2.sheetPixelHeight = 512;
    castle_2.colorKey = transparent;

    SpriteSheetProperties icons_1;

    icons_1.spriteSheetId = "icons_1";
    icons_1.fileName = "icons_1.png";
    icons_1.rows = 3;
    icons_1.columns = 4;
    icons_1.spriteSize = 140;
    icons_1.spriteCount = 12;
    icons_1.sheetPixelWidth = 560;
    icons_1.sheetPixelHeight = 480;
    icons_1.colorKey = transparent;

    mSpriteSheetProperties.push_back(castle_1);
    mSpriteSheetProperties.push_back(castle_2);
    mSpriteSheetProperties.push_back(icons_1);
}

const std::vector<SpriteSheetProperties> & SpriteSheetPropertiesImpl::getSpriteSheetProperties()
{
    return mSpriteSheetProperties;
}
