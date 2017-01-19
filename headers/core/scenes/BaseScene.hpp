class BaseScene : virtual public IScene
{

public:

BaseScene(const std::string & sceneId);
~BaseScene();

const std::string & getSceneId();
const std::string & getViewContextId();
const std::vector<std::string> & getMusicTrackIds();
const std::vector<std::string> & getMenuIds();

const std::vector<Viewport> & getViewports() const;

void update();

virtual void attach() = 0;
virtual void detatch() = 0;

protected:

void attachInputManagerToCamera();
void handleMusicPlaylist();

void detatchLayersFromMenuRenderer();
void detatchSceneRenderersFromViewports();

void attachLayersToMenuRenderer();
void attachSceneRenderersToViewports();
void attachUIElementsToEventManager();

void attachInputToUIMenus();
void detatchInputFromUIMenus();


std::string mSceneId;
std::string mViewContextId;

std::vector<std::string> mMusicTrackIds;
size_t mCurrentMusicTrackIdsIndex;
Window mWindow;

std::vector <Viewport> mViewports;
std::vector<std::string> mMenuIds;

MenuRenderer mMenuRenderer;
WorldRenderer mWorldRenderer;
MinimapRenderer mMinimapRenderer;
SelectedActionMenuRenderer mSelectedActionMenuRenderer;
StatusMenuRenderer mStatusMenuRenderer;

std::string mWorldRendererViewportId;
std::string mMinimapViewportId;
std::string mSelectedActionViewportId;
std::string mStatusMenuViewportId;

private:


};
