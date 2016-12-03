#include "include/global.hpp"

UIMenu::UIMenu()
{

}

UIMenu::~UIMenu()
{

}


std::vector<UIGridCell> & UIMenu::getGridCells()
{
    return mUIGridCells;
}

IMenuProperties * UIMenu::getIMenuProperties() const
{
    return mIMenuProperties;
}

void UIMenu::configure(IMenuProperties *IMenuProperties)
{
    mIMenuProperties = IMenuProperties;
    createGridCells();
}

void UIMenu::updateEnvelope(const SDL_Rect & envelope)
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
        repositionGridCells();
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

void UIMenu::repositionGridCells()
{
    const int columns = mIMenuProperties->getUIMenuProperties().columns;
    const int rows =  mIMenuProperties->getUIMenuProperties().rows;
    const int gridCellWidth = UIElement::getRect().w / columns;
    const int gridCellHeight = UIElement::getRect().h / rows;

    for (size_t linearIndex = 0; linearIndex < mUIGridCells.size(); linearIndex++)
    {
        const int thisColumn = linearIndex / mIMenuProperties->getUIMenuProperties().rows;
        const int thisRow = linearIndex %  mIMenuProperties->getUIMenuProperties().rows;
        const int x = (gridCellWidth * thisColumn) + UIElement::getRect().x;
        const int y = (gridCellHeight * thisRow) + UIElement::getRect().y;

        const SDL_Rect gridCellEnvelope = { x, y, gridCellWidth, gridCellHeight };
        mUIGridCells[linearIndex].updateEnvelope(gridCellEnvelope);
    }
}

void UIMenu::createGridCells()
{
    mUIGridCells.clear();
    const int columns = mIMenuProperties->getUIMenuProperties().columns;
    const int rows =  mIMenuProperties->getUIMenuProperties().rows;
    const int gridCellCount = rows * columns;

    std::vector<UIButton *> uiButtons;
    std::vector<UILabel *> uiLabels;
    createButtons(uiButtons);
    createLabels(uiLabels);

    for (int i = 0; i < gridCellCount; i++)
    {
        UIGridCell uiGridCell = UIGridCell(uiButtons[i], uiLabels[i]);
        mUIGridCells.push_back(uiGridCell);
    }
}

void UIMenu::createButtons(std::vector<UIButton *> & uiButtons)
{
    const std::vector<UIButtonProperties> & uiButtonProperties = mIMenuProperties->getUIButtonProperties();
    const std::vector<UIButtonStateProperties> & uiButtonStateProperties = mIMenuProperties->getUIButtonStateProperties();

    for (size_t i = 0; i < uiButtonProperties.size(); i++)
    {
        uiButtons.push_back(new UIButton(uiButtonProperties[i], uiButtonStateProperties));
    }
}

void UIMenu::createLabels(std::vector<UILabel *> & uiLabels)
{
    const std::vector<UILabelProperties> & uiLabelProperties = mIMenuProperties->getUILabelProperties();

    for (size_t i = 0; i < uiLabelProperties.size(); i++)
    {
        uiLabels.push_back(new UILabel(uiLabelProperties[i]));
    }
}
