class StartSceneImpl : public IScene
{

public:

StartSceneImpl::StartSceneImpl();
StartSceneImpl::~StartSceneImpl();

const std::string & getSceneId();
const std::string & getViewContextId();
const std::vector<std::string> & getMusicTrackIds();
const std::vector<std::string> & getMenuIds();

private:

void init();
void attachLayersToMenuRenderer();
void attachRenderersToViewports();
void attachInputHandlers();
void attachEventHandlers();
void handleMusicPlaylist();

std::string mSceneId;
std::string mViewContextId;
std::vector<std::string> mMusicTrackIds;
std::vector<std::string> mMenuIds;

Window & mWindow;
std::vector <Viewport> & mViewports;
AudioManager & mAudioManager;
InputEventManager *mInputEventManager;

size_t mCurrentMusicTrackIdsIndex;
MenuRenderer mMenuRenderer;

};
