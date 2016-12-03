class UIMenu : public UIElement, public ViewportObserver
{

public:

UIMenu();
~UIMenu();

const std::vector<SDL_Rect> &  getGridCells() const;
const std::vector<UIButton> & getUIButtons() const;
const std::vector<UILabel> & getUILabels() const;

std::vector<UIButton> & getUIButtonsRW();

void updateEnvelope(const SDL_Rect & envelope);
IMenuProperties * getIMenuProperties() const;
void configure(IMenuProperties *IMenuProperties);

private:

bool checkConfig();
void recalculateGridCellSize();

void createButtons();
void createLabels();
void updateEnvelopes();

SDL_Rect calculateRect(const int & linearIndex, const int & gridCellWidth, const int & gridCellHeight);

IMenuProperties *mIMenuProperties;

std::vector<SDL_Rect> mGridCells;
std::vector<UIButton> mUIButtons;
std::vector<UILabel> mUILabels;

};
