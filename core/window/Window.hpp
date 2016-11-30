class Window
{
public:

Window();
~Window();

SDL_Renderer * getWindowRenderer();

bool createWindow(const WindowProperties &windowProperties);
void clearScreen();
void updateScreen();


private:


bool init();

SDL_Window *mSDLWindow;
SDL_Renderer *mSDLWindowRenderer;

WindowProperties mWindowProperties;

};
