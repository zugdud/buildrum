class Surface : public Entity
{
public:

Surface();
~Surface();

void configure(const SurfaceProperties & surfaceProperties);
const SurfaceProperties & getSurfaceProperties();

private:

SurfaceProperties mSurfaceProperties;

};
