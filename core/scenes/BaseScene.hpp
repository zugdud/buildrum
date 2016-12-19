class BaseScene : virtual public IScene
{

public:

BaseScene(const std::string & sceneId);
~BaseScene();

const std::string & getSceneId();
const std::string & getViewContextId();
const std::vector<std::string> & getMusicTrackIds();
const std::vector<std::string> & getMenuIds();

void update();

void attach();
void detatch();

protected:

void handleMusicPlaylist();

std::string mSceneId;
std::string mViewContextId;

std::vector<std::string> mMusicTrackIds;
size_t mCurrentMusicTrackIdsIndex;
Window mWindow;

std::vector <Viewport> mViewports;
InputEventManager *mInputEventManager;
std::vector<std::string> mMenuIds;

MenuRenderer mMenuRenderer;
WorldRenderer mWorldRenderer;
MinimapRenderer mMinimapRenderer;

std::string mWorldRendererViewportId;
std::string mMinimapViewportId;

private:

void detatchLayersFromMenuRenderer();
void detatchSceneRenderersFromViewports();
void detatchInputManagerFromUIElements();

void attachLayersToMenuRenderer();
void attachSceneRenderersToViewports();
void attachInputManagerToUIElements();
void attachUIElementsToEventManager();
void attachInputManagerToCamera();

void attachWorld();
void detatchWorld();

void attachUIMenuAsEventObserver();
void detatchUIMenuAsEventObserver();
};
