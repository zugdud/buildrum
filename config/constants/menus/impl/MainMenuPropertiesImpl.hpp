class MainMenuPropertiesImpl : public BaseMenuProperties
{
public:

MainMenuPropertiesImpl();
~MainMenuPropertiesImpl();

void setProperties();

const UIMenuProperties & getUIMenuProperties() const;
const std::vector<UIButtonProperties> & getUIButtonProperties();

const std::vector<UILabelProperties> & getUILabelProperties();

private:

void setUIMenuProperties();
void setButtonProperties();
void setUILabelProperties();

};
