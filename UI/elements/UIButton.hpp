class UIButton : public UIElement, public PointEventObserver
{
public:

UIButton(const UIButtonProperties &uiButtonProperties, const std::vector<UIButtonStateProperties> &uiButtonStateProperties);
~UIButton();

const UIButtonProperties & getUIButtonProperties() const;
const UIButtonState & getCurrentUIButtonState();
void updateEnvelope(const SDL_Rect &envelope);
void configure(const UIButtonStateProperties &uiButtonStateProperties);

void pointEventCallback(PointInt pointInt);
void setUIEventConnector(UIEventConnector *uiEventConnector);

private:

bool setDefaultButtonState();
void addUIButtonStates(const std::vector<UIButtonStateProperties> & uiButtonStateProperties);

UIButtonProperties mUIButtonProperties;
UIEventConnector *mUIEventConnector;

std::string mCurrentUIButtonStateId;
std::map<std::string, UIButtonState> mUIButtonStates; // buttonStateId->buttonstate

};
