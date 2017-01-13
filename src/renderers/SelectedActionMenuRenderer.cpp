#include "include/global.hpp"

SelectedActionMenuRenderer::SelectedActionMenuRenderer()
{
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
        drawBorders();
        renderText("Action", mHeading);
        renderSelectedAction(mIcon);
    }
}

void SelectedActionMenuRenderer::drawBorders()
{
    renderBackground(mHeading);
    renderBorder(mHeading);
    renderBackground(mIcon);
    renderBorder(mIcon);
}

void SelectedActionMenuRenderer::renderObjectName(const SDL_Rect & cellRect)
{
    const std::string name = "Name: " + Player::Instance().getSelectedBuildableObjectProperties().entityProperties.entityId;

    renderText(name, cellRect);
}


void SelectedActionMenuRenderer::renderResourceCost(const SDL_Rect & cellRect)
{
    const std::string cost = "Cost: " + intToStr(Player::Instance().getSelectedBuildableObjectProperties().creditCost);

    renderText(cost, cellRect);
}


void SelectedActionMenuRenderer::renderSelectedAction(const SDL_Rect & cellRect)
{
    if (Player::Instance().getAction() == MOVE_ACTION)
    {
        const SpriteProperties & spriteProperties = ConfigManager::getInstance()->getSpritePropertiesImpl().getSpriteProperties("multiarrows_1");

        renderSprite(spriteProperties, cellRect);
    }
    else
    {
        const std::string & spriteName = Player::Instance().getSelectedBuildableObjectProperties().entityProperties.spriteLayers[0].spriteName_Up;
        const SpriteProperties & spriteProperties = ConfigManager::getInstance()->getSpritePropertiesImpl().getSpriteProperties(spriteName);

        renderSprite(spriteProperties, cellRect);
    }

}

void SelectedActionMenuRenderer::setLayout()
{
    mHeading = getCellRect(0, 0, 0.20);
    mIcon = getCellRect(0, mHeading.y + mHeading.h, 0.80);
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
