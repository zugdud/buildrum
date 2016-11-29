#include "include/global.hpp"

UIMenu::UIMenu(const UIMenuProperties & uiMenuProperties, const SDL_Rect & envelope)
{
    mUIMenuProperties = uiMenuProperties;
    UIElement::setRect(UIMenuProperties.xPadding, UIMenuProperties.yPadding, envelope);
}

UIMenu::~UIMenu()
{

}
