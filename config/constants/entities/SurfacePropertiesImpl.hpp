class SurfacePropertiesImpl
{
public:

Surfaces();
~Surfaces();

void loadAll();

std::vector<SurfaceProperties> & getSurfaceProperties();

private:

std::vector<SurfaceProperties> mSurfaceProperties;

};
