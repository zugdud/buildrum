class PlayerPaletteImpl
{
public:

PlayerPaletteImpl();
~PlayerPaletteImpl();

void loadAll();

const SurfaceProperties & getSurfaceProperties(const std::string entityId);

private:

void loadSurfaces();
void addSurface(const std::string & entityId,
                const int & spriteId,
                const std::string & spriteSheetId,
                const int & weightValue);

SpriteProperties buildSpriteProperties(const int & spriteId,
                                       const std::string spriteSheetId);

SpriteLayer buildSpriteLayer(const std::vector<SpriteProperties> & spriteProperties);

EntityProperties buildEntity(const std::string & entityId,
                             const std::vector<SpriteLayer> & spriteLayers);

InanimateObjectProperties buildInanimateObject(const EntityProperties & entityProperties,
                                               const HealthProperties & healthProperties);

std::map<std::string, InanimateObjectProperties> mInanimateObjectProperties;

};
