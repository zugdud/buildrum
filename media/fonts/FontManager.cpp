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

const FontTextures & getTexture(const std::string & fontName, const std::string & text)
{
    if (mTextures.at(fontName).textureExists(text))
    {
        return mTextures.at(fontName);
    }
    else
    {
        createFontTexture(text, mFontProperties.at(fontName));
        return mTextures.at(fontName);
    }
}

void FontManager::configure(const EnvironmentMediaPropertiesImpl &environmentMediaPropertiesImpl,
                            const FontPropertiesImpl &fontPropertiesImpl)
{
    SDL_Log("---------------------------------------------------- \n");
    SDL_Log("FontManager::configure -- Configuring... \n");
    mEnvironmentMediaProperties = environmentMediaPropertiesImpl;
    mFontPropertiesImpl = fontPropertiesImpl;
    init();
    SDL_Log("FontManager::configure -- Configuring Success. \n");
    SDL_Log("---------------------------------------------------- \n");
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
        loadAllMedia();
        return true;
    }
}

void FontManager::loadAllMedia()
{
    for (size_t i = 0; i < mFontProperties.size(); i++)
    {
        loadFont(mFontProperties[i]);
    }
}


void FontManager::loadFont(const FontProperties & fontProperties)
{
    const std::string relFilePath = mEnvironmentMediaProperties.fontDirName + fontProperties.filePath;
    TTF_Font *loadedFont = TTF_OpenFont(relFilePath.c_str(), fontProperties.fontSize);

    if ( loadedFont == NULL )
    {
        SDL_Log("Failed to load font -- fontName: %s relFilePath: %s SDL_ttf Error: %s \n", fontProperties.fontName.c_str(), relFilePath.c_str(), TTF_GetError());
    }
    else
    {

        mFontMap.insert(std::pair<std::string, TTF_Font * >(fontProperties.fontName, loadedFont) );

        FontTextures fontTextures = FontTextures();
        mFontMap.insert(std::pair<std::string, TTF_Font * >(fontProperties.fontName, fontTextures) );
    }
}

void FontManager::createFontTexture(const std::string & text, const FontProperties & fontProperties)
{
    SDL_Surface *textSurface = TTF_RenderText_Solid(mFontMap.at(fontProperties.fontName),
                                                    text.c_str(),
                                                    fontProperties.fontColor);

    if ( textSurface == NULL )
    {
        SDL_Log("FontManager::createFontTexture -- ERROR: Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
    }
    else
    {
        SDL_Rect textureRect = { 0, 0, textSurface.w, textSurface.h };
        fontTexture = SDL_CreateTextureFromSurface(WindowManager::getInstance()->getSDLRenderer(),
                                                   textSurface);

        if ( fontTexture == NULL )
        {
            SDL_Log("FontManager::createFontTexture -- ERROR: Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
        }
        else
        {
            mFontTextures.at(fontProperties.fontName).addTexture(text, textureRect, fontTexture);
            SDL_Log("FontManager::createFontTexture -- created new texture for text: [%s] fontName: [%s] textureRect: [w: %d h: %d] \n",
                    text,
                    fontProperties.fontName,
                    textureRect.w,
                    textureRect.h);
        }
        // temp surface
        SDL_FreeSurface(textSurface);
    }
}
