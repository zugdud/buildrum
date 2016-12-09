class SurfacePropertiesImpl
{
public:

SurfacePropertiesImpl();
~SurfacePropertiesImpl();

void loadAll();

const SurfaceProperties & getSurfaceProperties(const std::string entityId);

private:

void loadSurfaces();

std::map<std::string, SurfaceProperties> mSurfaceProperties;

};
