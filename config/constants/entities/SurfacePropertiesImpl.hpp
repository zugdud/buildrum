class SurfacePropertiesImpl
{
public:

Surfaces();
~Surfaces();

void loadAll();

const SurfaceProperties & getSurfaceProperties(const std::string entityId);

private:

std::map<std::string, SurfaceProperties> mSurfaceProperties;

};
