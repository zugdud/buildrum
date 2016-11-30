class FontProperties
{
public:

FontProperties();
~FontProperties();

void loadAll();
const EnvironmentMediaProperties & getEnvironmentMediaProperties();

private:

void setEnvironmentMediaProperties();
EnvironmentMediaProperties mEnvironmentMediaProperties;

};
