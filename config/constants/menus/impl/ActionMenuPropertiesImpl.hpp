class ActionMenuPropertiesImpl : public BaseMenuProperties
{
public:

ActionMenuPropertiesImpl();
~ActionMenuPropertiesImpl();

void setProperties();

private:

void setUIMenuProperties();
void setButtonProperties();
void setUILabelProperties();

};
