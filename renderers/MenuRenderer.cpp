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

void MenuRenderer::addLayer(UIMenu *uimenu)
{
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
                               uiCd.backgroundColor.red,
                               uiCd.backgroundColor.green,
                               uiCd.backgroundColor.blue,
                               uiCd.backgroundColor.alpha);
        SDL_RenderFillRect(mSDLRenderer, &cellRect);
    }

    if (uiCd.showbackgroundSprite)
    {
        // TODO backgroundSpriteId, cellRect
    }

    if (uiCd.showBorderColor)
    {
        SDL_SetRenderDrawColor(mSDLRenderer,
                               uiCd.outlineColor.red,
                               uiCd.outlineColor.green,
                               uiCd.outlineColor.blue,
                               uiCd.outlineColor.alpha);
        SDL_RenderDrawRect(mSDLRenderer, &cellRect);
    }

}

void MenuRenderer::renderLabel(UILabel *uiLabel)
{
    if (!uiLabel->getUILabelProperties().isSpacer)
    {
        const UILabelProperties & uiLP = uiLabel->getUILabelProperties();
        const SDL_Rect cellRect = uiLabel->getRect();

        const FontTextures & fontTextures = FontManager::getInstance()->getTextures(uiLP.fontProfileName, uiLP.labelText);

        SDL_Texture *labelTexture = fontTextures.getTexture(uiLP.labelText);
        const SDL_Rect & textureSize = fontTextures.getRect(uiLP.labelText);
        const SDL_Rect renderRect = { cellRect.x, cellRect.y, textureSize.w, textureSize.h };

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
        renderButton(uiGridCells[i].getUIButton());
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
