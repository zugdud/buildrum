class StatusMenuPropertiesImpl : public BaseMenuProperties
{
public:

StatusMenuPropertiesImpl();
~StatusMenuPropertiesImpl();

void setProperties();

private:

void setUIMenuProperties();
void setButtonProperties();
void setUILabelProperties();

};
