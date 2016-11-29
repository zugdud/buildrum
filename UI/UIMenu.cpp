#include "include/global.hpp"

UIMenu::UIMenu(const MenuPropertiesContainer & menuPropertiesContainer)
{
    mMenuPropertiesContainer = menuPropertiesContainer;
}

UIMenu::~UIMenu()
{

}

void UIMenu::resetPosition(const SDL_Rect & envelope)
{
    UIElement::setRect(mMenuPropertiesContainer.getUIMenuProperties().xPadding,
                       mMenuPropertiesContainer.getUIMenuProperties().yPadding,
                       envelope);
    UIElement::logDimensions(mMenuPropertiesContainer.getUIMenuProperties().uiMenuId);

    regenerateButtons();
    regenerateLabels();
}

void UIMenu::regenerateButtons()
{
    mUIButtons.clear();
    const std::vector<UIButtonProperties> & uiButtonProperties = mMenuPropertiesContainer.getUIButtonProperties();
    const std::vector<UIButtonStateProperties> & uiButtonStateProperties = mMenuPropertiesContainer.getUIButtonStateProperties();
    for (size_t i = 0; i < uiButtonProperties.size(); i++)
    {
        UIButton uiButton = UIButton(uiButtonStateProperties[i], UIElement::getRect(), uiButtonStateProperties);
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
