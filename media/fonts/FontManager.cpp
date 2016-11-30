#include "include/global.hpp"

FontManager::FontManager()
{

}

FontManager::~FontManager()
{
    // TODO
    // TTF_CloseFont();
    // TTF_Quit();
}

bool FontManager::init()
{
    bool success = false;

    // Initialize SDL_ttf
    if ( TTF_Init() == -1 )
    {
        printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
        success = false;
    }

    success = loadAllMedia();

    return success;
}

bool FontManager::loadAllMedia()
{
    for (size_t i = 0; i < mFontProperties.size(); i++)
    {
        loadFont(mFontProperties[i].fileName, mFontProperties[i].filePath);
    }

}


void FontManager::loadFont(std::string fontName, std::string filePath)
{
    std::string filePath = mEnvironmentMediaProperties + ""
        TTF_Font * loadedFont = TTF_OpenFont(filePath.c_str(), G_FONTMANAGER_PTSIZE);

    if ( loadedFont == NULL )
    {
        SDL_Log("Failed to load font -- fontName: %s filePath: %s SDL_ttf Error: %s \n", fontName.c_str(), filePath.c_str(), TTF_GetError());
    }
    else
    {
        // load success, map it
        mFontMap[fontId] = loadedFont;
    }
}
