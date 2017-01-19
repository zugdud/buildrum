class SceneManager
{

static SceneManager *mSingletonInstance;

public:

static SceneManager * getInstance();

void setActiveScene(const std::string & activeSceneId);
void updateActiveScene();
void init();

const bool & getUpdateLock();
void setUpdateLock(const bool & lockState);

SelectedPoint getViewportOffset(const PointInt & pointEvent);

protected:

SceneManager();
SceneManager(const SceneManager *);
SceneManager& operator=(const SceneManager *);
~SceneManager();

private:

bool isPointInViewport(const PointInt & pointInt, const SDL_Rect & rect);

bool mUpdateLock;

std::string mActiveSceneId;
std::map<std::string, IScene *> mScenes; // sceneId->scene
};
