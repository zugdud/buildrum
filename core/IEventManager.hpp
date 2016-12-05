class UIEventConnector
{

public:

virtual void uiEventRaised(const std::string & eventId) = 0;
virtual void newScene(const std::string & sceneId) = 0;

};
