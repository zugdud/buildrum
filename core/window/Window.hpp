class Window
{
public:

Window();
~Window();

SDL_Renderer * getWindowRenderer();

void clearScreen();
void updateScreen();


private:

bool createWindow();
bool init();

SDL_Window *mSDLWindow;
SDL_Renderer *mSDLWindowRenderer;

WindowProperties mWindowProperties;

};
