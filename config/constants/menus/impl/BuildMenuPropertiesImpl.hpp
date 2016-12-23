class BuildMenuPropertiesImpl : public BaseMenuProperties
{
public:

BuildMenuPropertiesImpl();
~BuildMenuPropertiesImpl();

void setProperties();

const UIMenuProperties & getUIMenuProperties() const;
const std::vector<UIButtonProperties> & getUIButtonProperties();

const std::vector<UILabelProperties> & getUILabelProperties();

private:

void setUIMenuProperties();
void setButtonProperties();
void setUILabelProperties();

};
