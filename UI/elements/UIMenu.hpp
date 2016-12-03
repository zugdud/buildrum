class UIMenu : public UIElement, public ViewportObserver
{

public:

UIMenu();
~UIMenu();

std::vector<UIGridCell> & getGridCells();

void updateEnvelope(const SDL_Rect & envelope);

IMenuProperties * getIMenuProperties() const;
void configure(IMenuProperties *IMenuProperties);

private:

bool checkConfig();

void createGridCells();
void createButtons(std::vector<UIButton *> & uiButtons);
void createLabels(std::vector<UILabel *> & uiLabels);

void repositionGridCells();

SDL_Rect calculateRect(const int & linearIndex, const int & gridCellWidth, const int & gridCellHeight);

IMenuProperties *mIMenuProperties;
std::vector<UIGridCell> mUIGridCells;

};
