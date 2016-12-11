class Entity
{
public:

Entity();
~Entity();

const EntityOrientation & getEntityOrientation() const;

protected:

EntityOrientation mEntityOrientation;

private:


};
