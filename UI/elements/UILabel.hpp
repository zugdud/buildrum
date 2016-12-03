class UILabel : public UIElement
{
public:

UILabel(const UILabelProperties & uiLabelProperties);
~UILabel();

void updateEnvelope(const SDL_Rect &envelope);
const UILabelProperties & getUILabelProperties() const;

private:

UILabelProperties mUILabelProperties;

};
