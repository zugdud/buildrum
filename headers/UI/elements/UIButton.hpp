class UIButton : public UIElement, public PointEventObserver
{
public:

UIButton(const UIButtonProperties &uiButtonProperties,
         const std::vector<UIButtonStateProperties> &uiButtonStateProperties,
         const UIMenuProperties & uiMenuProperties);
~UIButton();

const UIButtonProperties & getUIButtonProperties() const;
const UIButtonState & getCurrentUIButtonState();
void updateEnvelope(const SDL_Rect &envelope);
void configure(const UIButtonStateProperties &uiButtonStateProperties);

void pointEventCallback(PointInt pointInt);
void setUIEventConnector(UIEventConnector *uiEventConnector);

const std::string & getId();

const std::string & getViewportId() const;
const UIMenuProperties & getUIMenuProperties();

private:

bool setDefaultButtonState();
void addUIButtonStates(const std::vector<UIButtonStateProperties> & uiButtonStateProperties);

UIMenuProperties mParent_UIMenuProperties;

UIButtonProperties mUIButtonProperties;
UIEventConnector *mUIEventConnector;

std::string mCurrentUIButtonStateId;
std::map<std::string, UIButtonState> mUIButtonStates; // buttonStateId->buttonstate

};
