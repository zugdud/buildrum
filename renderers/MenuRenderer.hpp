class MenuRenderer
{
public:

MenuRenderer();
~MenuRenderer();

void renderMenu(const UIMenu & uiMenu);

private:

void renderCell(const UIRenderCellDetails & uiCd, const SDL_Rect & cellRect);
void renderLabel(const UILabelProperties & uiLP, const SDL_Rect & cellRect);

void renderGridCells(const UIMenu & uiMenu);
void renderButtons(const std::vector<UIButton> & uiButtons);
void renderLabels(const std::vector<UILabel> & uiLabels);

SDL_Renderer *mSDLRenderer;
};
