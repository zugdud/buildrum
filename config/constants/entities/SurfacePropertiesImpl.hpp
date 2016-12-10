class SurfacePropertiesImpl
{
public:

SurfacePropertiesImpl();
~SurfacePropertiesImpl();

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

SurfaceProperties buildSurface(const EntityProperties & entityProperties,
                               const int & weight);

std::map<std::string, SurfaceProperties> mSurfaceProperties;

};
