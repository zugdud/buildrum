#include "include/global.hpp"

UIGridCell::UIGridCell(UIButton *uiButton,  UILabel *uiLabel)
{
    mUIButton = uiButton;
    mUILabel = uiLabel;
}

UIGridCell::~UIGridCell()
{

}

void UIGridCell::updateEnvelope(const SDL_Rect &envelope)
{
    UIElement::setRect(envelope.x, envelope.y, envelope);
    UIElement::logRectDimensions("UIGridCell", "Setting grid cell", UIElement::getRect());

    mUIButton->updateEnvelope(envelope);
    mUILabel->updateEnvelope(envelope);
}

UIButton * UIGridCell::getUIButton()
{
    return mUIButton;
}
UILabel * UIGridCell::getUILabel()
{
    return mUILabel;
}
