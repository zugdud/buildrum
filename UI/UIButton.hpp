class UIButton : public UIElement
{
public:

UIButton(const UIButtonProperties & uiButtonProperties,
         const SDL_Rect & envelope,
         const std::vector<UIButtonStateProperties> & uiButtonStateProperties);
~UIButton();

const UIButtonProperties & getUIButtonProperties() const;
const UIButtonState & getCurrentUIButtonState() const;

private:

void checkConfig();
void addUIButtonStates(const std::vector<UIButtonStateProperties> & uiButtonStateProperties);

UIButtonProperties mUIButtonProperties;

UIButtonState mCurrentUIButtonState;
std::vector<UIButtonState> mUIButtonStates;

};
