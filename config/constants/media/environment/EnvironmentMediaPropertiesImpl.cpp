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
    mEnvironmentMediaProperties.mediaDirBasePath = "";
    mEnvironmentMediaProperties.imageDirName = "";
    mEnvironmentMediaProperties.soundEffectDirName = "files/media/soundEffects/";
    mEnvironmentMediaProperties.musicTrackDirName = "files/media/musicTracks/";
    mEnvironmentMediaProperties.fontDirName = "files/media/fonts/";
}

const EnvironmentMediaProperties & EnvironmentMediaPropertiesImpl::getEnvironmentMediaProperties()
{
    return mEnvironmentMediaProperties;
}
