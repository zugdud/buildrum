class BuildableObjectPropertiesImpl
{
public:

BuildableObjectPropertiesImpl();
~BuildableObjectPropertiesImpl();

void loadAll();

const BuildableObjectProperties & getBuildableObjectProperties(const std::string entityId);

private:

void loadSurfaces();
void addBuildableObjectProperties(const std::string & entityId,
                                  const std::string & spriteName,
                                  const int & maxHealth);

HealthProperties buildHealthProperties(const bool & isDestructable,
                                       const int & maxHealth,
                                       double & healthRegenerationRate);

SpriteLayer buildSpriteLayer(const std::vector<std::string>& spriteProperties);

EntityProperties buildEntity(const std::string & entityId,
                             const std::vector<SpriteLayer> & spriteLayers);

BuildableObjectProperties buildInanimateObject(const EntityProperties & entityProperties,
                                               const HealthProperties & healthProperties);

std::map<std::string, BuildableObjectProperties> mBuildableObjectProperties;

};
