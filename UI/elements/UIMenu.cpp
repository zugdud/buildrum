#include "include/global.hpp"

UIMenu::UIMenu()
{

}

UIMenu::~UIMenu()
{

}

const std::vector<SDL_Rect> & UIMenu::getGridCells() const
{
    return mGridCells;
}
const std::vector<UIButton> & UIMenu::getUIButtons() const
{
    return mUIButtons;
}
const std::vector<UILabel> & UIMenu::getUILabels() const
{
    return mUILabels;
}

void UIMenu::configure(IMenuProperties *IMenuProperties)
{
    mIMenuProperties = IMenuProperties;
}

// void UIMenu::viewportSwitchEvent(const Viewport & activeViewport)
// {
//     if (mIMenuProperties.getUIMenuProperties().viewportId == activeViewport.getViewportProperties().viewportId)
//     {
//         mEnvelope = activeViewport.getRect();
//     }
// }

IMenuProperties * UIMenu::getIMenuProperties() const
{
    return mIMenuProperties;
}

void UIMenu::resetPosition(const SDL_Rect & envelope)
{

    UIElement::setRect(mIMenuProperties->getUIMenuProperties().xPadding,
                       mIMenuProperties->getUIMenuProperties().yPadding,
                       envelope);

    std::string uiMenuId = mIMenuProperties->getUIMenuProperties().uiMenuId;
    std::string viewportId = mIMenuProperties->getUIMenuProperties().viewportId;
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

    const int columns = mIMenuProperties->getUIMenuProperties().columns;
    const int rows =  mIMenuProperties->getUIMenuProperties().rows;

    const std::vector<UIButtonProperties> & uiButtonProperties = mIMenuProperties->getUIButtonProperties();
    const std::vector<UILabelProperties> & uiLabelProperties = mIMenuProperties->getUILabelProperties();

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
    const int columns = mIMenuProperties->getUIMenuProperties().columns;
    const int rows =  mIMenuProperties->getUIMenuProperties().rows;
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
    const int rows =  mIMenuProperties->getUIMenuProperties().rows;

    const int thisColumn = linearIndex / rows;
    const int thisRow = linearIndex %  rows;
    const int x = (gridCellWidth * thisColumn) + UIElement::getRect().x;
    const int y = (gridCellHeight * thisRow) + UIElement::getRect().y;

    const SDL_Rect rect = { x, y, gridCellWidth, gridCellHeight };

    UIElement::logRectDimensions("UIMenu", "gridCell", rect);
    return rect;
}

void UIMenu::regenerateButtons()
{
    mUIButtons.clear();
    const std::vector<UIButtonProperties> & uiButtonProperties = mIMenuProperties->getUIButtonProperties();
    const std::vector<UIButtonStateProperties> & uiButtonStateProperties = mIMenuProperties->getUIButtonStateProperties();
    for (size_t i = 0; i < uiButtonProperties.size(); i++)
    {
        UIButton uiButton = UIButton(uiButtonProperties[i], mGridCells[i], uiButtonStateProperties);
        mUIButtons.push_back(uiButton);
    }
}

void UIMenu::regenerateLabels()
{
    mUILabels.clear();
    const std::vector<UILabelProperties> & uiLabelProperties = mIMenuProperties->getUILabelProperties();
    for (size_t i = 0; i < uiLabelProperties.size(); i++)
    {
        UILabel uiLabel = UILabel(uiLabelProperties[i], mGridCells[i]);
        mUILabels.push_back(uiLabel);
    }
}