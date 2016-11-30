#include "include/global.hpp"

MenuRenderer::MenuRenderer()
{
    mSDLRenderer = WindowManager::getInstance()->getSDLRenderer();
}

MenuRenderer::~MenuRenderer()
{

}

void MenuRenderer::renderMenu(const UIMenu & uiMenu)
{
    WindowManager::getInstance()->switchActiveViewport(uiMenu.getMenuPropertiesContainer().getUIMenuProperties().viewportId);
    drawGridCells(uiMenu);
    drawButtons(uiMenu.getUIButtons());

}

void MenuRenderer::drawCell(const UIRenderCellDetails & uiCd, const SDL_Rect & cellRect)
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

void MenuRenderer::drawGridCells(const UIMenu & uiMenu)
{
    const std::vector<SDL_Rect> & menuGridCells = uiMenu.getGridCells();
    const UIRenderCellDetails & uiCd = uiMenu.getMenuPropertiesContainer().getUIMenuProperties().uiRenderCellDetails;

    for (size_t i = 0; i < menuGridCells.size(); i++)
    {
        drawCell(uiCd, menuGridCells[i]);
    }
}

void MenuRenderer::drawButtons(const std::vector<UIButton> & uiButtons)
{
    for (size_t i = 0; i < uiButtons.size(); i++)
    {
        if (!uiButtons[i].getUIButtonProperties().isSpacer)
        {
            drawCell(uiButtons[i].getCurrentUIButtonState().getUIButtonStateProperties().uiRenderCellDetails, uiButtons[i].getRect());
        }
    }
}
