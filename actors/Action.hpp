class Action
{


public:


Action();
~Action();

void setBuildableObjectProperties(const std::string & entityId);

private:

BuildableObjectProperties mBuildableObjectProperties;

};
