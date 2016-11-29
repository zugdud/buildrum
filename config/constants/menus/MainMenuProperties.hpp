class MainMenuProperties : public IMenuProperties
{
public:

MainMenuProperties();
~MainMenuProperties();

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
