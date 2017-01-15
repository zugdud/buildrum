#include "include/global.hpp"

UIMenu::UIMenu()
{

}

UIMenu::~UIMenu()
{

}

void UIMenu::configure(IMenuProperties *IMenuProperties)
{
    mIMenuProperties = IMenuProperties;
    createGridCells();
    mHidden = mIMenuProperties->getUIMenuProperties().hidden;
}

void UIMenu::eventRaised(const std::string & eventId)
{
    SDL_Log("UIMenu::eventRaised -- eventId: %s \n", eventId.c_str());
    const std::string concatKey = "toggleHidden_" + mIMenuProperties->getUIMenuProperties().uiMenuId;

    if (eventId == concatKey)
    {
        toggleHidden();
    }

}

// void UIMenu::updateSpacerBgSprite()
// {
//
// }

void UIMenu::toggleHidden()
{
    if (mHidden == true)
    {
        mHidden = false;
        attach();
    }
    else
    {
        mHidden = true;
        detatch();
    }
}

void UIMenu::attach()
{
    if (!mHidden)
    {
        for (size_t i = 0; i < mUIGridCells.size(); i++)
        {
            mUIGridCells[i].attachInput();
        }
    }
}

void UIMenu::detatch()
{
    for (size_t i = 0; i < mUIGridCells.size(); i++)
    {
        mUIGridCells[i].detatchInput();
    }
}

const std::string & UIMenu::getId()
{
    return mIMenuProperties->getUIMenuProperties().uiMenuId;
}

const bool & UIMenu::isHidden()
{
    return mHidden;
}

std::vector<UIGridCell> & UIMenu::getGridCells()
{
    return mUIGridCells;
}

IMenuProperties * UIMenu::getIMenuProperties() const
{
    return mIMenuProperties;
}

void UIMenu::updateEnvelope(const SDL_Rect & envelope)
{
    // seperate the viewport offset
    SDL_Rect renderRect = { 0, 0, envelope.w, envelope.h };

    UIElement::setRect(mIMenuProperties->getUIMenuProperties().xPadding,
                       mIMenuProperties->getUIMenuProperties().yPadding,
                       renderRect);

    std::string uiMenuId = mIMenuProperties->getUIMenuProperties().uiMenuId;
    std::string viewportId = mIMenuProperties->getUIMenuProperties().viewportId;
    SDL_Log("---------------------------------------------------- \n");
    SDL_Log("UIMenu::resetPosition -- checking menu configuration for [uiMenuId: %s] [viewportId: %s] [hidden: %d]... \n",
            uiMenuId.c_str(),
            viewportId.c_str(),
            mHidden);
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
        SDL_Log("UIMenu::checkConfig -- ERROR: gridCellCount: %zu uiButtonProperties.size(): %zu \n", gridCellCount, uiButtonProperties.size());
        result = false;
    }
    if (gridCellCount != uiLabelProperties.size())
    {
        SDL_Log("UIMenu::checkConfig -- ERROR: gridCellCount: %zu uiLabelProperties.size(): %zu \n", gridCellCount, uiLabelProperties.size());
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

void UIMenu::setSelectedButton(const std::string & selectedButtonId)
{
    for (size_t i = 0; i < mUIGridCells.size(); i++)
    {
        UIButton *uiButton = mUIGridCells[i].getUIButton();
        if (uiButton->getUIButtonProperties().buttonId == selectedButtonId)
        {
            uiButton->setUIButtonState("buttonSelected");
        }
        else
        {
            uiButton->setUIButtonState("buttonAvailable");
        }
    }
}

void UIMenu::createButtons(std::vector<UIButton *> & uiButtons)
{
    const std::vector<UIButtonProperties> & uiButtonProperties = mIMenuProperties->getUIButtonProperties();

    for (size_t i = 0; i < uiButtonProperties.size(); i++)
    {
        const std::vector<UIButtonStateProperties> & uiButtonStateProperties = mIMenuProperties->getUIButtonStateProperties(uiButtonProperties[i].buttonId);
        uiButtons.push_back(new UIButton(uiButtonProperties[i], uiButtonStateProperties, mIMenuProperties->getUIMenuProperties()));
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
