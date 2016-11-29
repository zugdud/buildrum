#include "include/global.hpp"

UIMenu::UIMenu(const IUIMenuProperties & menuProperties, const SDL_Rect & envelope)
{
    IUIMenuProperties = mIUIMenuProperties;
    UIElement::setRect(UIMenuProperties.xPadding, UIMenuProperties.yPadding, envelope);
    UIElement::logDimensions(mIUImenuProperties.getUIMenuProperties.uiMenuId);
}

UIMenu::~UIMenu()
{

}


void UIMenu::addButtons()
{
    const std::vector<UIButtonProperties> & uiButtonProperties = mIUImenuProperties.getUIButtonProperties();
    const std::vector<UIButtonStateProperties> & uiButtonStateProperties = mIUImenuProperties.getUIButtonStateProperties();
    for (size_t i = 0; i < uiButtonProperties.size(); i++)
    {
        mUIButtons.push_back(new UIButton(uiButtonProperties[i]), UIElement::getRect(), uiButtonStateProperties);
    }
}

void UIMenu::addLabels()
{
    const std::vector<UILabelProperties> & uiLabelProperties = mIUImenuProperties.getUILabelProperties();
    for (size_t i = 0; i < uiLabelProperties.size(); i++)
    {
        mUILabels.push_back(new UIButton(uiLabelProperties[i]), UIElement::getRect());
    }
}
