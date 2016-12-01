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

bool setDefaultButtonState();
void addUIButtonStates(const std::vector<UIButtonStateProperties> & uiButtonStateProperties);

UIButtonProperties mUIButtonProperties;

std::string mCurrentUIButtonStateId;
std::map<std::string, UIButtonState> mUIButtonStates; // buttonStateId->buttonstate

};
