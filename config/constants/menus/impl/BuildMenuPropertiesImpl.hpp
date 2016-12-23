class BuildMenuPropertiesImpl : public BaseMenuProperties
{
public:

BuildMenuPropertiesImpl();
~BuildMenuPropertiesImpl();

void setProperties();

private:

void setUIMenuProperties();
void setButtonProperties();
void setUILabelProperties();

};
