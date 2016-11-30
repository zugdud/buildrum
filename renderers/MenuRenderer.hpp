class MenuRenderer
{
public:

MenuRenderer();
~MenuRenderer();

void renderMenu(const UIMenu & uiMenu);

private:

void drawCell(const UIRenderCellDetails & uiCd, const SDL_Rect & cellRect);
void drawGridCells(const UIMenu & uiMenu);
void drawButtons(const std::vector<UIButton> & uiButtons);

SDL_Renderer *mSDLRenderer;
};
