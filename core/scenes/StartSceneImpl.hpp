class StartSceneImpl : virtual public IScene
{

public:

StartSceneImpl();
~StartSceneImpl();

const std::string & getSceneId();
const std::string & getViewContextId();
const std::vector<std::string> & getMusicTrackIds();
const std::vector<std::string> & getMenuIds();

void update();

void attach();
void detatch();

private:

void init();

void detatchLayersToMenuRenderer();

void attachLayersToMenuRenderer();
void attachSceneRenderersToViewports();
void attachInputManagerToUIElements();
void attachUIElementsToEventManager();

void handleMusicPlaylist();

std::string mSceneId;
std::string mViewContextId;
std::vector<std::string> mMusicTrackIds;
std::vector<std::string> mMenuIds;

Window mWindow;
std::vector <Viewport> mViewports;
AudioManager *mAudioManager;
InputEventManager *mInputEventManager;

size_t mCurrentMusicTrackIdsIndex;
MenuRenderer mMenuRenderer;

};
