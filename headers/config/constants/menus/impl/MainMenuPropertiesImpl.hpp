class MainMenuPropertiesImpl : public BaseMenuProperties
{
public:

MainMenuPropertiesImpl();
~MainMenuPropertiesImpl();

void setProperties();

private:

void setUIMenuProperties();
void setButtonProperties();
void setUILabelProperties();

};
