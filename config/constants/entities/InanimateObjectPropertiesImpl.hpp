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
                                  const int & spriteId,
                                  const std::string & spriteSheetId,
                                  const int & maxHealth);

HealthProperties buildHealthProperties(const bool & isDestructable,
                                       const int & maxHealth,
                                       double & healthRegenerationRate);

SpriteProperties buildSpriteProperties(const int & spriteId,
                                       const std::string spriteSheetId);

SpriteLayer buildSpriteLayer(const std::vector<SpriteProperties> & spriteProperties);

EntityProperties buildEntity(const std::string & entityId,
                             const std::vector<SpriteLayer> & spriteLayers);

InanimateObjectProperties buildInanimateObject(const EntityProperties & entityProperties,
                                               const HealthProperties & healthProperties);

std::map<std::string, InanimateObjectProperties> mInanimateObjectProperties;

};
