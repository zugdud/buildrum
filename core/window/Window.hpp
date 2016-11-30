class Window
{
public:

Window();
~Window();

SDL_Renderer * getSDLWindowRenderer();

bool createWindow(const WindowProperties &windowProperties);
void clearScreen() const;
void updateScreen() const;


private:


bool init();

SDL_Window *mSDLWindow;
SDL_Renderer *mSDLWindowRenderer;

WindowProperties mWindowProperties;

};
