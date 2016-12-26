class Player
{


public:


Player();
~Player();

void setBuildableAction(const std::string & entityId);

private:

BuildableActionProperties mBuildableActionProperties;

};
