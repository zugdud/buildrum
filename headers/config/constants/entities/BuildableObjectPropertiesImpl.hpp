class BuildableObjectPropertiesImpl
{
public:

BuildableObjectPropertiesImpl();
~BuildableObjectPropertiesImpl();

void loadAll();

const BuildableObjectProperties & getBuildableObjectProperties(const std::string & entityId) const;

private:

void loadSurfaces();
void addBuildableObjectProperties(const std::string & entityId,
                                  const std::string & spriteName,
                                  const int & maxHealth,
                                  const int & creditCost);

CombatProperties buildCombatProperties(const bool & isAttacker,
                                       const int & range,
                                       const int & damage,
                                       const int & apCost);

HealthProperties buildHealthProperties(const bool & isDestructable,
                                       const int & maxHealth,
                                       double & healthRegenerationRate);

SpriteLayer buildSpriteLayer(const std::vector<std::string>& spriteProperties);

EntityProperties buildEntity(const std::string & entityId,
                             const std::vector<SpriteLayer> & spriteLayers);

BuildableObjectProperties buildBuildableObject(const EntityProperties & entityProperties,
                                               const HealthProperties & healthProperties,
                                               const CombatProperties & combatProperties,
                                               const int & creditCost);

std::map<std::string, BuildableObjectProperties> mBuildableObjectProperties;

};
