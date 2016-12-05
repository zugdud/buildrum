class SceneManager
{

static SceneManager *mSingletonInstance;

public:

static SceneManager * getInstance();

void setActiveScene(const std::string & activeSceneId);
void updateActiveScene();
void init();

protected:

SceneManager();
SceneManager(const SceneManager *);
SceneManager& operator=(const SceneManager *);
~SceneManager();

private:

std::string mActiveSceneId;
std::map<std::string, IScene *> mScenes; // sceneId->scene
};
