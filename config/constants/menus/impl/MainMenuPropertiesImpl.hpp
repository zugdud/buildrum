class MainMenuPropertiesImpl : public IMenuProperties
{
public:

MainMenuPropertiesImpl();
~MainMenuPropertiesImpl();

void setProperties();

const UIMenuProperties & getUIMenuProperties() const;
const std::vector<UIButtonProperties> & getUIButtonProperties();
const std::vector<UIButtonStateProperties> & getUIButtonStateProperties();
const std::vector<UILabelProperties> & getUILabelProperties();

private:

void setUIMenuProperties();
void setButtonProperties();
void setUILabelProperties();

void setUIButtonStateProperties(const std::string & buttonId, const SpriteProperties & spriteProperties);

UIMenuProperties mUIMenuProperties;
std::vector<UIButtonProperties> mUIButtonProperties;
std::vector<UIButtonStateProperties> mUIButtonStateProperties;
std::vector<UILabelProperties> mUILabelProperties;

};
