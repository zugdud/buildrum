#include "include/global.hpp"

MenuPropertiesContainer::MenuPropertiesContainer()
{

}

MenuPropertiesContainer::~MenuPropertiesContainer()
{

}

void MenuPropertiesContainer::setUIMenuProperties(const UIMenuProperties & uiMenuProperties)
{
    mUIMenuProperties = uiMenuProperties;
}
void MenuPropertiesContainer::addUIButtonProperties(const UIButtonProperties & uiButtonProperties)
{
    mUIButtonProperties.push_back(uiButtonProperties);
}
void MenuPropertiesContainer::addUIButtonStateProperties(const UIButtonStateProperties & uiButtonStateProperties)
{
    mUIButtonStateProperties.push_back(uiButtonStateProperties);
}
void MenuPropertiesContainer::addUILabelProperties(const UILabelProperties & uiLabelProperties)
{
    mUILabelProperties.push_back(uiLabelProperties);
}

const UIMenuProperties & MenuPropertiesContainer::getUIMenuProperties()
{
    return mUIMenuProperties;
}
const std::vector<UIButtonProperties> & MenuPropertiesContainer::getUIButtonProperties()
{
    return mUIButtonProperties;
}
const std::vector<UIButtonStateProperties> & MenuPropertiesContainer::getUIButtonStateProperties()
{
    return mUIButtonStateProperties;
}
const std::vector<UILabelProperties> & MenuPropertiesContainer::getUILabelProperties()
{
    return mUILabelProperties;
}
