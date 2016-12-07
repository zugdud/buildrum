class Surface : public Entity
{
public:

Surface();
~Surface();

void configure(const SurfaceProperties & surfaceProperties);

private:

SurfaceProperties mSurfaceProperties;

};
