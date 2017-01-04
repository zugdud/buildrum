class SurfacePropertiesImpl
{
public:

SurfacePropertiesImpl();
~SurfacePropertiesImpl();

void loadAll();

const SurfaceProperties & getSurfaceProperties(const std::string & entityId) const;

private:

void loadSurfaces();

void addSurface(const std::string & entityId,
                const std::string & spriteName,
                const int & weightValue);

SpriteLayer buildSpriteLayer(const std::vector<std::string> & spriteProperties);

EntityProperties buildEntity(const std::string & entityId,
                             const std::vector<SpriteLayer> & spriteLayers);

SurfaceProperties buildSurface(const EntityProperties & entityProperties,
                               const int & weight);

std::map<std::string, SurfaceProperties> mSurfaceProperties;

};
