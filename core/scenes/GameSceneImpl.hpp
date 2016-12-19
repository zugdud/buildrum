class GameSceneImpl : public BaseScene
{

public:

GameSceneImpl(const std::string & sceneId);
~GameSceneImpl();

void attach();
void detatch();

private:

void doLoadAction();

};
