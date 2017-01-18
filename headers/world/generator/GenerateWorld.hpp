class GenerateWorld
{
public:

GenerateWorld();
~GenerateWorld();

void createWorld(const std::string & worldId);
const World & getWorld();

void setPaths();

private:

TestWorldImpl mTestWorldImpl;

World mWorld;
};
