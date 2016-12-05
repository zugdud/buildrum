class IScene
{

public:

virtual const std::string & getSceneId() = 0;
virtual const std::string & getViewContextId() = 0;
virtual const std::vector<std::string> & getMusicTrackIds() = 0;
virtual const std::vector<std::string> & getMenuIds() = 0;

virtual void update() = 0;
};
