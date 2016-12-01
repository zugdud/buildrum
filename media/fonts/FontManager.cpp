#include "include/global.hpp"

FontManager *FontManager::mSingletonInstance = 0;

FontManager::FontManager()
{

}

FontManager::~FontManager()
{
    // TODO
    // TTF_CloseFont();
    // TTF_Quit();
}

FontManager * FontManager::getInstance()
{
    if (!mSingletonInstance)
    {
        mSingletonInstance = new FontManager;
    }
    return mSingletonInstance;
}

const FontTextures & FontManager::getTextures(const std::string & fontProfileName, const std::string & text)
{
    if (mFontTextures.at(fontProfileName).textureExists(text))
    {
        return mFontTextures.at(fontProfileName);
    }
    else
    {
        createFontTexture(text, mFontProfiles.at(fontProfileName));
        return mFontTextures.at(fontProfileName);
    }
}

bool FontManager::configure(const EnvironmentMediaPropertiesImpl &environmentMediaPropertiesImpl,
                            const FontProfileImpl &FontProfileImpl)
{
    SDL_Log("---------------------------------------------------- \n");
    SDL_Log("FontManager::configure -- Configuring... \n");
    mEnvironmentMediaPropertiesImpl = environmentMediaPropertiesImpl;
    mFontProfileImpl = FontProfileImpl;

    if (init())
    {
        SDL_Log("FontManager::configure -- sizes mFontProfiles: %lu mFontMap: %lu mFontTextures: %lu \n", mFontProfiles.size(), mFontMap.size(), mFontTextures.size());
        SDL_Log("FontManager::configure -- Configuring Success. \n");
        SDL_Log("---------------------------------------------------- \n");
        return true;
    }

    SDL_Log("FontManager::configure -- ERROR: Configuring Failure! \n");
    SDL_Log("---------------------------------------------------- \n");
    return false;
}

bool FontManager::init()
{
    // Initialize SDL_ttf
    if ( TTF_Init() == -1 )
    {
        SDL_Log("FontManager::init -- SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
        return false;
    }
    else
    {
        SDL_Log("FontManager::init -- SDL_ttf init success, loading all fonts...\n");
        if (!loadAllMedia())
        {
            return false;
        }
    }
    return true;
}

bool FontManager::loadAllMedia()
{
    const std::vector<FontProfile> & fontProfiles = mFontProfileImpl.getFontProfiles();
    for (size_t i = 0; i < fontProfiles.size(); i++)
    {
        mFontProfiles.insert(std::pair<std::string, FontProfile>(fontProfiles[i].fontProfileName, fontProfiles[i]) );
        if (!loadFont(fontProfiles[i]))
        {
            return false;
        }
    }
    return true;
}

bool FontManager::loadFont(const FontProfile &fontProfiles)
{
    const std::string relFilePath = mEnvironmentMediaPropertiesImpl.getEnvironmentMediaProperties().fontDirName + fontProfiles.filePath;
    TTF_Font *loadedFont = TTF_OpenFont(relFilePath.c_str(), fontProfiles.fontSize);

    if ( loadedFont == NULL )
    {
        SDL_Log("FontManager::loadFont -- ERROR: Failed to load font fontProfileName: %s relFilePath: %s SDL_ttf Error: %s \n", fontProfiles.fontProfileName.c_str(), relFilePath.c_str(), TTF_GetError());
        return false;
    }
    else
    {
        mFontMap.insert(std::pair<std::string, TTF_Font * >(fontProfiles.fontProfileName, loadedFont) );
        mFontTextures.insert(std::pair<std::string, FontTextures>(fontProfiles.fontProfileName, FontTextures()) );
        SDL_Log("FontManager::loadFont -- loaded fontProfileName: %s \n", fontProfiles.fontProfileName.c_str());
        return true;
    }
}

void FontManager::createFontTexture(const std::string & text, const FontProfile & fontProfiles)
{
    SDL_Surface *textSurface = TTF_RenderText_Solid(mFontMap.at(fontProfiles.fontProfileName),
                                                    text.c_str(),
                                                    fontProfiles.fontColor);

    if ( textSurface == NULL )
    {
        SDL_Log("FontManager::createFontTexture -- ERROR: Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
    }
    else
    {
        SDL_Rect textureRect = { 0, 0, textSurface->w, textSurface->h };
        SDL_Texture *fontTexture = SDL_CreateTextureFromSurface(WindowManager::getInstance()->getSDLRenderer(),
                                                                textSurface);

        if ( fontTexture == NULL )
        {
            SDL_Log("FontManager::createFontTexture -- ERROR: Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
        }
        else
        {

            mFontTextures.at(fontProfiles.fontProfileName).addTexture(text, textureRect, fontTexture);
            SDL_Log("FontManager::createFontTexture -- created new texture for text: [%s] fontProfileName: [%s] textureRect: [w: %d h: %d] \n",
                    text.c_str(),
                    fontProfiles.fontProfileName.c_str(),
                    textureRect.w,
                    textureRect.h);
        }
        // temp surface
        SDL_FreeSurface(textSurface);
    }
}
