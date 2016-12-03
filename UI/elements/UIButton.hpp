class UIButton : public UIElement, public PointEventObserver
{
public:

UIButton(const UIButtonProperties &uiButtonProperties, const std::vector<UIButtonStateProperties> &uiButtonStateProperties);
~UIButton();

const UIButtonProperties & getUIButtonProperties() const;
const UIButtonState & getCurrentUIButtonState() const;
void updateEnvelope(const SDL_Rect &envelope);

void pointEventCallback(PointInt pointInt);

private:

bool setDefaultButtonState();
void addUIButtonStates(const std::vector<UIButtonStateProperties> & uiButtonStateProperties);

UIButtonProperties mUIButtonProperties;

std::string mCurrentUIButtonStateId;
std::map<std::string, UIButtonState> mUIButtonStates; // buttonStateId->buttonstate

};
