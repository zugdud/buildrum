class EnvironmentMediaPropertiesImpl
{
public:

EnvironmentMediaPropertiesImpl();
~EnvironmentMediaPropertiesImpl();

void loadAll();
const EnvironmentMediaProperties & getEnvironmentMediaProperties();

private:

void setEnvironmentMediaProperties();
EnvironmentMediaProperties mEnvironmentMediaProperties;

};
