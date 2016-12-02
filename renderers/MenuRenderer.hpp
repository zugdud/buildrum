class MenuRenderer : public IRenderer
{
public:

MenuRenderer();
~MenuRenderer();

void addLayer(const UIMenu & uimenu);
void renderAllLayers();
void updatePositionAllLayers();

private:

void renderLayer(const UIMenu & uiMenu);

void renderCell(const UIRenderCellDetails & uiCd, const SDL_Rect & cellRect);
void renderLabel(const UILabelProperties & uiLP, const SDL_Rect & cellRect);

void renderGridCells(const UIMenu & uiMenu);
void renderButtons(const std::vector<UIButton> & uiButtons);
void renderLabels(const std::vector<UILabel> & uiLabels);

SDL_Renderer *mSDLRenderer;
std::vector<UIMenu> mLayers;

};
