#include "include/global.hpp"

UIMenu::UIMenu()
{

}

UIMenu::~UIMenu()
{

}

void UIMenu::configure(const MenuPropertiesContainer &menuPropertiesContainer)
{
    mMenuPropertiesContainer = menuPropertiesContainer;
}

// void UIMenu::viewportSwitchEvent(const Viewport & activeViewport)
// {
//     if (mMenuPropertiesContainer.getUIMenuProperties().viewportId == activeViewport.getViewportProperties().viewportId)
//     {
//         mEnvelope = activeViewport.getRect();
//     }
// }

const MenuPropertiesContainer & UIMenu::getMenuPropertiesContainer()
{
    return mMenuPropertiesContainer;
}

void UIMenu::resetPosition(const SDL_Rect & envelope)
{

    UIElement::setRect(mMenuPropertiesContainer.getUIMenuProperties().xPadding,
                       mMenuPropertiesContainer.getUIMenuProperties().yPadding,
                       envelope);

    std::string uiMenuId = mMenuPropertiesContainer.getUIMenuProperties().uiMenuId;
    std::string viewportId = mMenuPropertiesContainer.getUIMenuProperties().viewportId;
    SDL_Log("---------------------------------------------------- \n");
    SDL_Log("UIMenu::resetPosition -- checking menu configuration for [uiMenuId: %s] [viewportId: %s]... \n",
            uiMenuId.c_str(),
            viewportId.c_str());
    if (checkConfig())
    {
        UIElement::logRectDimensions("UIMenu", "Envelope", envelope);
        UIElement::logRectDimensions("UIMenu", uiMenuId, UIElement::getRect());
        recalculateGridCellSize();
        regenerateButtons();
        regenerateLabels();
        SDL_Log("UIMenu::resetPosition -- resetPosition Success! \n");
    }
    else
    {
        SDL_Log("UIMenu::resetPosition -- ERROR: Not updating position due to checkConfig() failure! \n");
    }
    SDL_Log("---------------------------------------------------- \n");
}

bool UIMenu::checkConfig()
{

    bool result = true;

    const int columns = mMenuPropertiesContainer.getUIMenuProperties().columns;
    const int rows =  mMenuPropertiesContainer.getUIMenuProperties().rows;

    const std::vector<UIButtonProperties> & uiButtonProperties = mMenuPropertiesContainer.getUIButtonProperties();
    const std::vector<UILabelProperties> & uiLabelProperties = mMenuPropertiesContainer.getUILabelProperties();

    const size_t gridCellCount = rows * columns;

    if (gridCellCount != uiButtonProperties.size())
    {
        SDL_Log("UIMenu::checkConfig -- ERROR: gridCellCount: %lu uiButtonProperties.size(): %lu \n", gridCellCount, uiButtonProperties.size());
        result = false;
    }
    if (gridCellCount != uiLabelProperties.size())
    {
        SDL_Log("UIMenu::checkConfig -- ERROR: gridCellCount: %lu uiLabelProperties.size(): %lu \n", gridCellCount, uiLabelProperties.size());
        result = false;
    }

    return result;
}

void UIMenu::recalculateGridCellSize()
{
    mGridCells.clear();
    const int columns = mMenuPropertiesContainer.getUIMenuProperties().columns;
    const int rows =  mMenuPropertiesContainer.getUIMenuProperties().rows;
    const int gridCellCount = rows * columns;
    const int gridCellWidth = UIElement::getRect().w / columns;
    const int gridCellHeight = UIElement::getRect().h / rows;

    for (int linearIndex = 0; linearIndex < gridCellCount; linearIndex++)
    {
        mGridCells.push_back(calculateRect(linearIndex, gridCellWidth, gridCellHeight));
    }
}

SDL_Rect UIMenu::calculateRect(const int & linearIndex, const int & gridCellWidth, const int & gridCellHeight)
{
    const int rows =  mMenuPropertiesContainer.getUIMenuProperties().rows;

    const int thisColumn = linearIndex / rows;
    const int thisRow = linearIndex %  rows;
    const int x = gridCellWidth * thisColumn;
    const int y = gridCellHeight * thisRow;

    const SDL_Rect rect = { x, y, gridCellWidth, gridCellHeight };

    UIElement::logRectDimensions("UIMenu", "gridCell", rect);
    return rect;
}

void UIMenu::regenerateButtons()
{
    mUIButtons.clear();
    const std::vector<UIButtonProperties> & uiButtonProperties = mMenuPropertiesContainer.getUIButtonProperties();
    const std::vector<UIButtonStateProperties> & uiButtonStateProperties = mMenuPropertiesContainer.getUIButtonStateProperties();
    for (size_t i = 0; i < uiButtonProperties.size(); i++)
    {
        UIButton uiButton = UIButton(uiButtonProperties[i], UIElement::getRect(), uiButtonStateProperties);
        mUIButtons.push_back(uiButton);
    }
}

void UIMenu::regenerateLabels()
{
    mUILabels.clear();
    const std::vector<UILabelProperties> & uiLabelProperties = mMenuPropertiesContainer.getUILabelProperties();
    for (size_t i = 0; i < uiLabelProperties.size(); i++)
    {
        UILabel uiLabel = UILabel(uiLabelProperties[i], UIElement::getRect());
        mUILabels.push_back(uiLabel);
    }
}
