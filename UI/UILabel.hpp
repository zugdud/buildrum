class UILabel : public UIElement
{
public:

UILabel(const UILabelProperties & uiLabelProperties, const SDL_Rect & envelope);
~UILabel();

private:

UILabelProperties mUILabelProperties;

};
