#include "include/global.hpp"

EnvironmentMediaPropertiesImpl::EnvironmentMediaPropertiesImpl()
{

}

EnvironmentMediaPropertiesImpl::~EnvironmentMediaPropertiesImpl()
{

}

void EnvironmentMediaPropertiesImpl::loadAll()
{
    setEnvironmentMediaProperties();
}

void EnvironmentMediaPropertiesImpl::setEnvironmentMediaProperties()
{
    mEnvironmentMediaProperties.mediaDirBasePath = "";
    mEnvironmentMediaProperties.imageDirName = "";
    mEnvironmentMediaProperties.soundEffectDirName = "";
    mEnvironmentMediaProperties.musicTrackDirName = "";
    mEnvironmentMediaProperties.fontDirName = "files/media/fonts/";
}

const EnvironmentMediaProperties & EnvironmentMediaPropertiesImpl::getEnvironmentMediaProperties()
{
    return mEnvironmentMediaProperties;
}
