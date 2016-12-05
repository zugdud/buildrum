#include "include/global.hpp"

MenuRenderer::MenuRenderer()
{
    mSDLRenderer = WindowManager::getInstance()->getSDLRenderer();
}

MenuRenderer::~MenuRenderer()
{

}

std::vector<UIMenu *> & MenuRenderer::getAllLayers()
{
    return mLayers;
}

void MenuRenderer::removeLayer(const std::string & uiMenuId)
{
    for (size_t i = 0; i < mLayers.size(); i++)
    {
        if (mLayers[i]->getIMenuProperties()->getUIMenuProperties().uiMenuId == uiMenuId )
        {
            SDL_Log("MenuRenderer::removeLayer -- removing menu from renderer, uiMenuId: %s \n",
                    uiMenuId.c_str());
            mLayers.erase(mLayers.begin() + i);
        }

    }
}


void MenuRenderer::addLayer(UIMenu *uimenu)
{
    SDL_Log("MenuRenderer::addLayer -- adding menu to renderer, uiMenuId: %s \n",
            uimenu->getIMenuProperties()->getUIMenuProperties().uiMenuId.c_str());
    mLayers.push_back(uimenu);
}

void MenuRenderer::renderAllLayers()
{
    for (size_t i = 0; i < mLayers.size(); i++)
    {
        renderLayer(mLayers[i]);
    }
}

void MenuRenderer::renderLayer(UIMenu *uiMenu)
{
    renderGridCells(uiMenu);
}

void MenuRenderer::renderCell(const UIRenderCellDetails & uiCd, const SDL_Rect & cellRect)
{
    if (uiCd.showBackgroundColor)
    {
        SDL_SetRenderDrawColor(mSDLRenderer,
                               uiCd.backgroundColor.r,
                               uiCd.backgroundColor.g,
                               uiCd.backgroundColor.b,
                               uiCd.backgroundColor.a);
        SDL_RenderFillRect(mSDLRenderer, &cellRect);
    }

    if (uiCd.showbackgroundSprite)
    {
        // TODO backgroundSpriteId, cellRect
    }

    if (uiCd.showBorderColor)
    {
        SDL_SetRenderDrawColor(mSDLRenderer,
                               uiCd.outlineColor.r,
                               uiCd.outlineColor.g,
                               uiCd.outlineColor.b,
                               uiCd.outlineColor.a);
        SDL_RenderDrawRect(mSDLRenderer, &cellRect);
    }

}

void MenuRenderer::renderLabel(UILabel *uiLabel)
{
    if (!uiLabel->getUILabelProperties().isSpacer)
    {
        const UILabelProperties & uiLP = uiLabel->getUILabelProperties();
        const SDL_Rect cellRect = uiLabel->getRect();

        FontTextures & fontTextures = FontManager::getInstance()->getTextures(uiLP.fontProfileName, uiLP.labelText);

        SDL_Texture *labelTexture = fontTextures.getTexture(uiLP.labelText);
        const SDL_Rect & textureSize = fontTextures.getRect(uiLP.labelText);


        SDL_Rect renderRect = { cellRect.x, cellRect.y, textureSize.w, textureSize.h };
        const int heightPadding = (cellRect.h - textureSize.h) / 2;
        renderRect.y = cellRect.y + heightPadding;     // center y axis

        if (uiLP.alignment == "center")
        {
            const int widthPadding = (cellRect.w - textureSize.w) / 2;
            renderRect.x = cellRect.x + widthPadding; // center padding offset
        }
        else
        {
            // default left alignment
            renderRect.x = cellRect.x + uiLP.xPadding;
        }

        SDL_RenderCopy(mSDLRenderer, labelTexture, NULL, &renderRect);
    }
}

void MenuRenderer::renderGridCells(UIMenu *uiMenu)
{
    std::vector<UIGridCell> & uiGridCells = uiMenu->getGridCells();
    const UIRenderCellDetails & gridCellDetails = uiMenu->getIMenuProperties()->getUIMenuProperties().uiRenderCellDetails;

    for (size_t i = 0; i < uiGridCells.size(); i++)
    {
        renderCell(gridCellDetails, uiGridCells[i].getRect());
    }
    for (size_t i = 0; i < uiGridCells.size(); i++)
    {
        renderButton(uiGridCells[i].getUIButton());
    }
    for (size_t i = 0; i < uiGridCells.size(); i++)
    {
        renderLabel(uiGridCells[i].getUILabel());
    }
}

void MenuRenderer::renderButton(UIButton *uiButton)
{
    if (!uiButton->getUIButtonProperties().isSpacer)
    {
        renderCell(uiButton->getCurrentUIButtonState().getUIButtonStateProperties().uiRenderCellDetails,
                   uiButton->getRect());
    }
}
