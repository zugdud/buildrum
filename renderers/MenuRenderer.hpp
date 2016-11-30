class MenuRenderer
{
public:

MenuRenderer();
~MenuRenderer();

void renderMenu(const UIMenu & uiMenu);

private:

void drawGridCells(const UIMenu & uiMenu);

SDL_Renderer *mSDLRenderer;
};
