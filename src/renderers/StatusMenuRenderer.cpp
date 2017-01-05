#include "include/global.hpp"

StatusMenuRenderer::StatusMenuRenderer()
{
    mLabelTextProfile = "Heading_3_OpenSansLight";
}

StatusMenuRenderer::~StatusMenuRenderer()
{

}

const bool & StatusMenuRenderer::isAttached()
{
    return mAttached;
}

void StatusMenuRenderer::attach(const Viewport &viewport)
{
    mAttached = true;

    SDL_Rect borderRect = { 0, 0, viewport.getRect().w, viewport.getRect().h };
    mBorder = borderRect;

    SDL_Log("----------------------------------------------------\n");
    SDL_Log("StatusMenuRenderer::attached -- setting up ... \n");
    setLayout();
    SDL_Log("----------------------------------------------------\n");
}

void StatusMenuRenderer::detatch()
{
    mAttached = false;
    SDL_Log("StatusMenuRenderer::detatch -- detatched, rendering stopped. \n");
}


void StatusMenuRenderer::render()
{
    if (mAttached)
    {
        drawBorders();
        renderText("Stats", mHeading);
        renderCreditsRemaining(mCreditsRemain);
    }
}

void StatusMenuRenderer::setLayout()
{
    mHeading = getCellRect(0, 0, 0.20);
    mCreditsRemain = getCellRect(0, mHeading.y + mHeading.h, 0.20);
}

void StatusMenuRenderer::drawBorders()
{
    renderBackground(mHeading);
    renderBorder(mHeading);
    renderBackground(mCreditsRemain);
    renderBorder(mCreditsRemain);
}

void StatusMenuRenderer::renderCreditsRemaining(const SDL_Rect & cellRect)
{
    const std::string credits = "Credits: " + intToStr(Player::Instance().getCredits());

    renderText(credits, cellRect);
}

SDL_Rect StatusMenuRenderer::getCellRect(const int & offsetX, const int & offsetY, const double & scale)
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

std::string StatusMenuRenderer::intToStr(const int & value)
{
    std::string result;
    std::ostringstream convert;

    convert << value;
    result = convert.str();
    return result;
}

void StatusMenuRenderer::renderBorder(const SDL_Rect & cellRect)
{
    SDL_SetRenderDrawColor(mSDLRenderer, 0, 255, 0, 255);
    SDL_RenderDrawRect(mSDLRenderer, &cellRect);
}

void StatusMenuRenderer::renderBackground(const SDL_Rect & cellRect)
{
    SDL_SetRenderDrawColor(mSDLRenderer, 100, 0, 150, 255);
    SDL_RenderFillRect(mSDLRenderer, &cellRect);
}

void StatusMenuRenderer::renderText(const std::string & text, const SDL_Rect & cellRect)
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
