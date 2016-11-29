#include "include/global.hpp"

MenuProperties::MenuProperties()
{

}
MenuProperties::~MenuProperties()
{

}

void MenuProperties::setUIMenuProperties(const UIMenuProperties & uiMenuProperties)
{
    mUIMenuProperties = uiMenuProperties;
}
void MenuProperties::addUIButtonProperties(const UIButtonProperties & uiButtonProperties)
{
    mUIButtonProperties.push_back(uiButtonProperties);
}
void MenuProperties::addUIButtonStateProperties(const UIButtonStateProperties & uiButtonStateProperties)
{
    mUIButtonStateProperties.push_back(uiButtonStateProperties);
}
void MenuProperties::addUILabelProperties(const UILabelProperties & uiLabelProperties)
{
    mUILabelProperties.push_back(uiLabelProperties);
}

const UIMenuProperties & MenuProperties::getUIMenuProperties()
{
    return mUIMenuProperties;
}
const std::vector<UIButtonProperties> & MenuProperties::getUIButtonProperties()
{
    return mUIButtonProperties;
}
const std::vector<UIButtonStateProperties> & MenuProperties::getUIButtonStateProperties()
{
    return mUIButtonStateProperties;
}
const std::vector<UILabelProperties> & MenuProperties::getUILabelProperties()
{
    return mUILabelProperties;
}
