class UIGridCell : public UIElement
{
public:

UIGridCell(UIButton *uiButton, UILabel *uiLabel);
~UIGridCell();

UIButton * getUIButton();
UILabel * getUILabel();

void updateEnvelope(const SDL_Rect &envelope);

private:

UIButton *mUIButton;
UILabel *mUILabel;

};
