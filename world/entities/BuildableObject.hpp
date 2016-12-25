class InanimateObject : public Entity
{
public:

InanimateObject();
~InanimateObject();

void configure(const BuildableObjectProperties & surfaceProperties);
const BuildableObjectProperties & getBuildableObjectProperties() const;

void setOrientation(const EntityOrientation & orientation);

private:

BuildableObjectProperties mBuildableObjectProperties;

};
