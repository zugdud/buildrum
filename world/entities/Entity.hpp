class Entity
{
public:

Entity();
~Entity();

const EntityOrientation &getEntityOrientation() const;
const std::vector<SpriteProperties> & getSpriteProperties() const;

protected:

EntityOrientation mEntityOrientation;
std::vector<SpriteProperties> mSpriteProperties;

private:


};
