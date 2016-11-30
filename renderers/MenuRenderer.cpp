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
}

void MenuRenderer::drawGridCells(const UIMenu & uiMenu)
{
    const std::vector<SDL_Rect> & menuGridCells = uiMenu.getGridCells();
    const RGBAColors bgcolor = uiMenu.getMenuPropertiesContainer().getUIMenuProperties().bgColor;
    const RGBAColors gridLineColor = uiMenu.getMenuPropertiesContainer().getUIMenuProperties().gridLineColor;

    for (size_t i = 0; i < menuGridCells.size(); i++)
    {
        SDL_SetRenderDrawColor(mSDLRenderer,
                               bgcolor.red,
                               bgcolor.green,
                               bgcolor.blue,
                               bgcolor.alpha);
        SDL_RenderFillRect(mSDLRenderer, &menuGridCells[i]);

        SDL_SetRenderDrawColor(mSDLRenderer,
                               gridLineColor.red,
                               gridLineColor.green,
                               gridLineColor.blue,
                               gridLineColor.alpha);
        SDL_RenderDrawRect(mSDLRenderer, &menuGridCells[i]);
    }
}
