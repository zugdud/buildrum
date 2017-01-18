class StartSceneImpl : public BaseScene
{

public:

StartSceneImpl(const std::string & sceneId);
~StartSceneImpl();

void attachInputManagerToCamera();

void attach();
void detatch();

private:


};
