#include "include/global.hpp"


SpriteSheetManager::SpriteSheetManager()
{

}

SpriteSheetManager::~SpriteSheetManager()
{

}

bool SpriteSheetManager::configure(const EnvironmentMediaPropertiesImpl &environmentMediaPropertiesImpl,
                                   const SpriteSheetPropertiesImpl &spriteSheetPropertiesImpl)
{
    mEnvironmentMediaPropertiesImpl = environmentMediaPropertiesImpl;
    mSpriteSheetPropertiesImpl = spriteSheetPropertiesImpl;
    SDL_Log("---------------------------------------------------- \n");
    SDL_Log("SpriteSheetManager::configure -- loading sprite sheets... \n");

    bool success = loadSpriteSheets();
    SDL_Log("---------------------------------------------------- \n");
    return success;
}

SpriteSheet * SpriteSheetManager::getSpriteSheet(const std::string & spriteSheetId)
{
    if (mSpriteSheets.count(spriteSheetId) == 1)
    {
        return mSpriteSheets[spriteSheetId];
    }
    else
    {
        SDL_Log("SpriteSheetManager::getSpriteSheet -- ERROR spriteSheetId not found: %s  \n", spriteSheetId.c_str());
        return NULL;
    }
}

bool SpriteSheetManager::loadSpriteSheets()
{
    const std::vector<SpriteSheetProperties> & spriteSheetProperties = mSpriteSheetPropertiesImpl.getSpriteSheetProperties();

    for (size_t i = 0; i < spriteSheetProperties.size(); i++)
    {
        SpriteSheet *spriteSheet = new SpriteSheet();
        bool success = spriteSheet->configure(mEnvironmentMediaPropertiesImpl, spriteSheetProperties[i]);
        if (success)
        {
            const std::string spriteSheetId = spriteSheetProperties[i].spriteSheetId;
            mSpriteSheets[spriteSheetId] = spriteSheet;
            SDL_Log("SpriteSheetManager::loadSpriteSheets added spriteSheetId: %s to map size: %zu \n", spriteSheetId.c_str(), mSpriteSheets.size());
        }
        else
        {
            return false;
        }
    }
    return true;
}
