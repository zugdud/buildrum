class MenuProperties
{
public:

MenuProperties();
~MenuProperties();

void setUIMenuProperties(const UIMenuProperties & uiMenuProperties);
void addUIButtonProperties(const UIButtonProperties & uiButtonProperties);
void addUIButtonStateProperties(const UIButtonStateProperties & uiButtonStateProperties);
void addUILabelProperties(const UILabelProperties & uiLabelProperties);

const UIMenuProperties & getUIMenuProperties();
const std::vector<UIButtonProperties> & getUIButtonProperties();
const std::vector<UIButtonStateProperties> & getUIButtonStateProperties();
const std::vector<UILabelProperties> & getUILabelProperties();

private:

UIMenuProperties mUIMenuProperties;
std::vector<UIButtonProperties> mUIButtonProperties;
std::vector<UIButtonStateProperties> mUIButtonStateProperties;
std::vector<UILabelProperties> mUILabelProperties;

};
