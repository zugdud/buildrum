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
    renderButtons(uiMenu->getUIButtons());
    renderLabels(uiMenu->getUILabels());
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

void MenuRenderer::renderLabel(const UILabelProperties & uiLP, const SDL_Rect & cellRect)
{
    const FontTextures & fontTextures = FontManager::getInstance()->getTextures(uiLP.fontProfileName, uiLP.labelText);

    SDL_Texture *labelTexture = fontTextures.getTexture(uiLP.labelText);
    const SDL_Rect & textureSize = fontTextures.getRect(uiLP.labelText);
    const SDL_Rect destRect = { cellRect.x, cellRect.y, textureSize.w, textureSize.h };

    SDL_RenderCopy(mSDLRenderer, labelTexture, NULL, &destRect);
}

void MenuRenderer::renderGridCells(UIMenu *uiMenu)
{
    const std::vector<SDL_Rect> & menuGridCells = uiMenu->getGridCells();
    const UIRenderCellDetails & uiCd = uiMenu->getIMenuProperties()->getUIMenuProperties().uiRenderCellDetails;

    for (size_t i = 0; i < menuGridCells.size(); i++)
    {
        renderCell(uiCd, menuGridCells[i]);
    }
}

void MenuRenderer::renderButtons(const std::vector<UIButton> & uiButtons)
{
    for (size_t i = 0; i < uiButtons.size(); i++)
    {
        if (!uiButtons[i].getUIButtonProperties().isSpacer)
        {
            renderCell(uiButtons[i].getCurrentUIButtonState().getUIButtonStateProperties().uiRenderCellDetails, uiButtons[i].getRect());
        }
    }
}

void MenuRenderer::renderLabels(const std::vector<UILabel> & uiLabels)
{
    for (size_t i = 0; i < uiLabels.size(); i++)
    {
        if (!uiLabels[i].getUILabelProperties().isSpacer)
        {
            renderLabel(uiLabels[i].getUILabelProperties(), uiLabels[i].getRect());
        }
    }
}
