class InanimateObjectPropertiesImpl
{
public:

InanimateObjectPropertiesImpl();
~InanimateObjectPropertiesImpl();

void loadAll();

const InanimateObjectProperties & getInanimateObjectProperties(const std::string entityId);

private:

void loadSurfaces();
void addInanimateObjectProperties(const std::string & entityId,
                                  const std::string & spriteName,
                                  const int & maxHealth);

HealthProperties buildHealthProperties(const bool & isDestructable,
                                       const int & maxHealth,
                                       double & healthRegenerationRate);

SpriteLayer buildSpriteLayer(const std::vector<std::string>& spriteProperties);

EntityProperties buildEntity(const std::string & entityId,
                             const std::vector<SpriteLayer> & spriteLayers);

InanimateObjectProperties buildInanimateObject(const EntityProperties & entityProperties,
                                               const HealthProperties & healthProperties);

std::map<std::string, InanimateObjectProperties> mInanimateObjectProperties;

};
