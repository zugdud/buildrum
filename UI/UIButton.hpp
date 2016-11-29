class UIButton : public UIElement
{
public:

UIButton(const UIButtonProperties & uiButtonProperties, const SDL_Rect & envelope, const std::vector<UIButtonStateProperties> & uiButtonStateProperties);
~UIButton();


private:

void addUIButtonStates(const std::vector<UIButtonStateProperties> & uiButtonStateProperties);

UIButtonProperties mUIButtonProperties;
std::vector<UIButtonState> mUIButtonStates;

};
