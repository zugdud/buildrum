class MainMenuPropertiesImpl : public IMenuProperties
{
public:

MainMenuPropertiesImpl();
~MainMenuPropertiesImpl();

void setProperties(MenuPropertiesContainer & menuPropertiesContainer);

private:

void setUIMenuProperties(MenuPropertiesContainer & menuPropertiesContainer);
void setButtonProperties(MenuPropertiesContainer & menuPropertiesContainer);
void setUILabelProperties(MenuPropertiesContainer & menuPropertiesContainer);
void setUIButtonStateProperties(MenuPropertiesContainer & menuPropertiesContainer);

};
