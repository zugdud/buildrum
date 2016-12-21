class InanimateObject : public Entity
{
public:

InanimateObject();
~InanimateObject();

void configure(const InanimateObjectProperties & surfaceProperties);
const InanimateObjectProperties & getInanimateObjectProperties() const;

void setOrientation(const EntityOrientation & orientation);

private:

InanimateObjectProperties mInanimateObjectProperties;

};
