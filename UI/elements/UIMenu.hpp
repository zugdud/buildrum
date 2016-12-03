class UIMenu : public UIElement, public ViewportObserver
{

public:

UIMenu();
~UIMenu();

const std::vector<UIGridCell> &  getGridCells() const;

void updateEnvelope(const SDL_Rect & envelope);

IMenuProperties * getIMenuProperties() const;
void configure(IMenuProperties *IMenuProperties);

private:

bool checkConfig();

void createGridCells();
void createButtons();
void createLabels();

void repositionGridCells();

SDL_Rect calculateRect(const int & linearIndex, const int & gridCellWidth, const int & gridCellHeight);

IMenuProperties *mIMenuProperties;
std::vector<UIGridCell> mUIGridCells;

};
