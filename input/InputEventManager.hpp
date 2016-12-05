class InputEventManager
{

static InputEventManager *mSingletonInstance;

public:

static InputEventManager * getInstance();

void registerQuitEventObserver(QuitEventObserver *quitEventObserver);
void registerPointEventObserver(PointEventObserver *pointEventObserver);

void pollEventQueue();

protected:

InputEventManager();
InputEventManager(const InputEventManager *);
InputEventManager& operator=(const InputEventManager *);
~InputEventManager();

private:

void dispatchPointEvent(const SDL_Event & sdlEvent);

std::vector<QuitEventObserver *> mQuitEventObservers;
std::vector<PointEventObserver *> mPointEventObserver;

};
