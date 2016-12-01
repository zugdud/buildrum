class UIMenu : public UIElement
{
public:

UIMenu();
~UIMenu();

const std::vector<SDL_Rect> &  getGridCells() const;
const std::vector<UIButton> & getUIButtons() const;
const std::vector<UILabel> & getUILabels() const;

void viewportSwitchEvent(const Viewport & activeViewport);
void resetPosition(const SDL_Rect & envelope);
IMenuProperties * getIMenuProperties() const;
void configure(IMenuProperties *IMenuProperties);

private:

bool checkConfig();
void recalculateGridCellSize();
void regenerateButtons();
void regenerateLabels();

SDL_Rect calculateRect(const int & linearIndex, const int & gridCellWidth, const int & gridCellHeight);

IMenuProperties *mIMenuProperties;

std::vector<SDL_Rect> mGridCells;
std::vector<UIButton> mUIButtons;
std::vector<UILabel> mUILabels;

};
