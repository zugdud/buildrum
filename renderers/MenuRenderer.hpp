class MenuRenderer : public IRenderer
{
public:

MenuRenderer();
~MenuRenderer();

void addLayer(UIMenu *uimenu);
void renderAllLayers();
std::vector<UIMenu *> & getAllLayers();

private:

void renderGridCells(UIMenu *uiMenu);
void renderLayer(UIMenu *uiMenu);
void renderButton(UIButton *uiButton);
void renderLabel(UILabel *uiLabel);

void renderCell(const UIRenderCellDetails & uiCd, const SDL_Rect & cellRect);

SDL_Renderer *mSDLRenderer;
std::vector<UIMenu *> mLayers;

};
