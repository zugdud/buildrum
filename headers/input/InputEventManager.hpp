class InputEventManager
{

static InputEventManager *mSingletonInstance;

public:

static InputEventManager * getInstance();

void registerQuitEventObserver(QuitEventObserver *quitEventObserver);
void registerPointEventObserver(PointEventObserver *pointEventObserver);
void registerScrollEventObserver(ScrollEventObserver *scrollEventObserver);
void registerZoomEventObserver(ZoomEventObserver *zoomEventObserver);

void removePointEventObserver(const std::string & id);


void update();

protected:

InputEventManager();
InputEventManager(const InputEventManager *);
InputEventManager& operator=(const InputEventManager *);
~InputEventManager();

private:

void handleKeyEvents(const SDL_Event & sdlEvent);
void handleMultiTouch(const SDL_Event & sdlEvent);
void handleFingerMotion(const SDL_Event & sdlEvent);

void dispatchQuitEvent();
void dispatchScrollEvent(const PointInt & momentum);
void dispatchZoomEvent(const double & zoomFactor);
void dispatchPointEvent(const SDL_Event & sdlEvent);

std::vector<QuitEventObserver *> mQuitEventObservers;
std::vector<PointEventObserver *> mPointEventObserver;

std::vector<ScrollEventObserver *> mScrollEventObservers;
std::vector<ZoomEventObserver *> mZoomEventObservers;

InputMomentum mInputMomentum;

};
