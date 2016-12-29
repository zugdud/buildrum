#include "include/global.hpp"

SelectedActionMenuRenderer::SelectedActionMenuRenderer()
{
    mSDLRenderer = WindowManager::getInstance()->getSDLRenderer();
    mLabelTextProfile = "Heading_3_OpenSansLight";
}

SelectedActionMenuRenderer::~SelectedActionMenuRenderer()
{

}

const bool & SelectedActionMenuRenderer::isAttached()
{
    return mAttached;
}

void SelectedActionMenuRenderer::attach(const Viewport &viewport)
{
    mAttached = true;

    SDL_Rect borderRect = { 0, 0, viewport.getRect().w, viewport.getRect().h };
    mBorder = borderRect;

    SDL_Log("----------------------------------------------------\n");
    SDL_Log("SelectedActionMenuRenderer::attached -- setting up ... \n");
    setLayout();
    SDL_Log("----------------------------------------------------\n");
}

void SelectedActionMenuRenderer::detatch()
{
    mAttached = false;
    SDL_Log("SelectedActionMenuRenderer::detatch -- detatched, rendering stopped. \n");
}

void SelectedActionMenuRenderer::render()
{
    if (mAttached)
    {
        for (size_t i = 0; i < mLayout.size(); i++)
        {

            renderBackground(mLayout[i]);
            renderBorder(mLayout[i]);
            if (i == 0)
            {
                renderSelectedAction(mLayout[i]);
            }
            renderText("test: " + intToStr(i), mLayout[i]);
        }
    }
}

void SelectedActionMenuRenderer::renderSelectedAction(const SDL_Rect & cellRect)
{
    const std::string & spriteName =  Player::Instance().getSelectedBuildableObjectProperties().entityProperties.spriteLayers[0].spriteName_Up;
    const SpriteProperties & spriteProperties = ConfigManager::getInstance()->getSpritePropertiesImpl().getSpriteProperties(spriteName);

    renderSprite(spriteProperties, cellRect);
}

void SelectedActionMenuRenderer::setLayout()
{
    mLayout.clear();

    SDL_Rect icon = getCellRect(0, 0, 0.60);
    SDL_Rect name = getCellRect(0, icon.y + icon.h, 0.20);
    SDL_Rect cost = getCellRect(0, name.y + name.h, 0.20);

    mLayout.push_back(icon);
    mLayout.push_back(name);
    mLayout.push_back(cost);
}

SDL_Rect SelectedActionMenuRenderer::getCellRect(const int & offsetX, const int & offsetY, const double & scale)
{
    const int xPadding = 4;
    const int yPadding = 4;

    SDL_Rect rect;

    rect.x = (mBorder.x + xPadding) + offsetX;
    rect.y = (mBorder.y + yPadding) + offsetY;
    rect.w = mBorder.w - (xPadding * 2);
    rect.h = (mBorder.h * scale) - (yPadding * 2);

    SDL_Log("SelectedActionMenuRenderer::getCellRect -- rect: [x: %d y: %d w: %d h: %d] \n",
            rect.x,
            rect.y,
            rect.w,
            rect.h);

    return rect;
}

std::string SelectedActionMenuRenderer::intToStr(const int & value)
{
    std::string result;
    std::ostringstream convert;
    convert << value;
    result = convert.str();
    return result;
}

void SelectedActionMenuRenderer::renderBorder(const SDL_Rect & cellRect)
{
    SDL_SetRenderDrawColor(mSDLRenderer, 0, 255, 0, 255);
    SDL_RenderDrawRect(mSDLRenderer, &cellRect);
}

void SelectedActionMenuRenderer::renderBackground(const SDL_Rect & cellRect)
{
    SDL_SetRenderDrawColor(mSDLRenderer, 100, 0, 150, 255);
    SDL_RenderFillRect(mSDLRenderer, &cellRect);
}

void SelectedActionMenuRenderer::renderText(const std::string & text, const SDL_Rect & cellRect)
{

    FontTextures & fontTextures = FontManager::getInstance()->getTextures(mLabelTextProfile, text);

    SDL_Texture *labelTexture = fontTextures.getTexture(text);
    const SDL_Rect & textureSize = fontTextures.getRect(text);

    SDL_Rect renderRect = { cellRect.x, cellRect.y, textureSize.w, textureSize.h };
    const int heightPadding = (cellRect.h - textureSize.h) / 2;

    renderRect.y = cellRect.y + heightPadding;         // center y axis

    // default left alignment
    const int textPadding = 5;
    renderRect.x = cellRect.x + textPadding;

    SDL_RenderCopy(mSDLRenderer, labelTexture, NULL, &renderRect);
}

void SelectedActionMenuRenderer::renderSprite(const SpriteProperties & spriteProperties, const SDL_Rect & destRect)
{
    SDL_Point *center = NULL;
    SDL_Texture *spriteSheetTexture = SpriteSheetManager::Instance().getSpriteSheet(spriteProperties.spriteSheetId).getTexture();
    const SDL_Rect & spriteRect = SpriteSheetManager::Instance().getSpriteSheet(spriteProperties.spriteSheetId).getSprite(spriteProperties.spriteId).getRect();

    SDL_RenderCopyEx(mSDLRenderer,
                     spriteSheetTexture,
                     &spriteRect,
                     &destRect,
                     spriteProperties.angle,
                     center,
                     spriteProperties.sdlRendererFlip);
}
