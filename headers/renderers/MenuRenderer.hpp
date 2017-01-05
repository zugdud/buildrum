class MenuRenderer : public IRenderer, public BaseRenderer
{
public:

MenuRenderer();
~MenuRenderer();

void addLayer(UIMenu *uimenu);
void removeLayer(const std::string & menuId);

void renderAllLayers(const std::string & viewportId);
std::vector<UIMenu *> & getAllLayers();

private:

void renderGridCells(UIMenu *uiMenu);
void renderLayer(UIMenu *uiMenu);
void renderButton(UIButton *uiButton);
void renderLabel(UILabel *uiLabel);

bool checkMenuStatus(UIMenu *uiMenu, const std::string & viewportId);

void renderCell(const UIRenderCellDetails & uiCd, const SDL_Rect & cellRect);

std::vector<UIMenu *> mLayers;

};
