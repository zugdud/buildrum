#include "include/global.hpp"

EnvironmentMediaPropertiesImpl::EnvironmentMediaPropertiesImpl()
{

}

EnvironmentMediaPropertiesImpl::~EnvironmentMediaPropertiesImpl()
{

}

void EnvironmentMediaPropertiesImpl::loadAll()
{
    SDL_Log("EnvironmentMediaPropertiesImpl::loadAll -- loading configuration ...\n");
    setEnvironmentMediaProperties();
}

void EnvironmentMediaPropertiesImpl::setEnvironmentMediaProperties()
{
    mEnvironmentMediaProperties.spriteSheetDirPath = "files/media/spriteSheets/";
    mEnvironmentMediaProperties.soundEffectDirPath = "files/media/soundEffects/";
    mEnvironmentMediaProperties.musicTrackDirPath = "files/media/musicTracks/";
    mEnvironmentMediaProperties.fontDirPath = "files/media/fonts/";
}

const EnvironmentMediaProperties & EnvironmentMediaPropertiesImpl::getEnvironmentMediaProperties()
{
    return mEnvironmentMediaProperties;
}
