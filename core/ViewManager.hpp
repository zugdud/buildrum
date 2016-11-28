class ViewManager
{
public:

ViewManager();
~ViewManager();

bool init();
void clearScreen();
void updateScreen();
void close();
bool createWindow();

private:
SDL_Window *mWindow;
SDL_Renderer *mWindowRenderer;

int mScreenWidth;
int mScreenHeight;
private:

};
