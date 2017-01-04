class UIGridCell : public UIElement
{
public:

UIGridCell(UIButton *uiButton, UILabel *uiLabel);
~UIGridCell();

UIButton * getUIButton();
UILabel * getUILabel();

void attachInput();
void detatchInput();

void updateEnvelope(const SDL_Rect &envelope);

private:

UIButton *mUIButton;
UILabel *mUILabel;

};
