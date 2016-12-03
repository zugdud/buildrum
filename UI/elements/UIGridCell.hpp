class UIGridCell : public UIElement
{
public:

UIGridCell(const UIButton & uiButton,
           const UILabel & uiLabel);
~UIGridCell();

const UIButton & getUIButton();
const UILabel & getUILabel();

void updateEnvelope(const SDL_Rect &envelope);

private:

UIButton mUIButton;
UILabel mUILabel;

};
