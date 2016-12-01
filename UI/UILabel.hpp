class UILabel : public UIElement
{
public:

UILabel(const UILabelProperties & uiLabelProperties, const SDL_Rect & envelope);
~UILabel();

const UILabelProperties & getUILabelProperties() const;

private:

UILabelProperties mUILabelProperties;

};
