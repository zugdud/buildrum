class LoadingSceneImpl : public BaseScene
{

public:

LoadingSceneImpl(const std::string & sceneId);
~LoadingSceneImpl();


void startThread();

void attach();
void detatch();

private:

};
