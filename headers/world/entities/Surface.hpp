class Surface : public Entity
{
public:

Surface();
~Surface();

void configure(const SurfaceProperties & surfaceProperties);
const SurfaceProperties & getSurfaceProperties() const;

void setOrientation(const EntityOrientation & orientation);

private:

SurfaceProperties mSurfaceProperties;

};
