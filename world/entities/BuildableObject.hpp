class BuildableObject : public Entity
{
public:

BuildableObject();
~BuildableObject();

void configure(const BuildableObjectProperties & surfaceProperties);
const BuildableObjectProperties & getBuildableObjectProperties() const;

void setOrientation(const EntityOrientation & orientation);

private:

BuildableObjectProperties mBuildableObjectProperties;

};
