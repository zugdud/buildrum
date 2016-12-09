class GenerateWorld
{
public:

GenerateWorld();
~GenerateWorld();

void createWorld(const std::string & worldId);
const World & getWorld();

private:

TestWorldImpl mTestWorldImpl;

World mWorld;
};
