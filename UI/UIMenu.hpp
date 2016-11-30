class UIMenu : public UIElement
{
public:

UIMenu();
~UIMenu();

const std::vector<SDL_Rect> &  getGridCells() const;
const std::vector<UIButton> & getUIButtons();
const std::vector<UILabel> & getUILabels();

void viewportSwitchEvent(const Viewport & activeViewport);
void resetPosition(const SDL_Rect & envelope);
const MenuPropertiesContainer & getMenuPropertiesContainer() const;
void configure(const MenuPropertiesContainer &menuPropertiesContainer);

private:

bool checkConfig();
void recalculateGridCellSize();
void regenerateButtons();
void regenerateLabels();

SDL_Rect calculateRect(const int & linearIndex, const int & gridCellWidth, const int & gridCellHeight);

MenuPropertiesContainer mMenuPropertiesContainer;

std::vector<SDL_Rect> mGridCells;
std::vector<UIButton> mUIButtons;
std::vector<UILabel> mUILabels;

};
