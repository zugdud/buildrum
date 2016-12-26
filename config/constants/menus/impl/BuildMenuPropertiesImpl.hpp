class BuildMenuPropertiesImpl : public BaseMenuProperties
{
public:

BuildMenuPropertiesImpl();
~BuildMenuPropertiesImpl();

void setProperties();

private:

void setSpriteNames(std::vector<std::string> & spriteNames);

void setUIMenuProperties();
void setButtonProperties(std::vector<std::string> & spriteNames);
void setUILabelProperties(std::vector<std::string> & spriteNames);

};
