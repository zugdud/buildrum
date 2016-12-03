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

void renderCell(const UIRenderCellDetails & uiCd, const SDL_Rect & cellRect);
void renderLabel(const UILabelProperties & uiLP, const SDL_Rect & cellRect);
void renderButton(const std::vector<UIButton> & uiButtons);

SDL_Renderer *mSDLRenderer;
std::vector<UIMenu *> mLayers;

};
