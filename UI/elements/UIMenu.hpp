class UIMenu : public UIElement, public IEventObserver
{

public:

UIMenu();
~UIMenu();

void eventRaised(const std::string & eventId);
const std::string & getId();

std::vector<UIGridCell> & getGridCells();

void updateEnvelope(const SDL_Rect & envelope);

IMenuProperties * getIMenuProperties() const;
void configure(IMenuProperties *IMenuProperties);

const bool & isHidden();

void toggleHidden();
void attach();
void detatch();

private:

bool checkConfig();

void createGridCells();
void createButtons(std::vector<UIButton *> & uiButtons);
void createLabels(std::vector<UILabel *> & uiLabels);

void repositionGridCells();

SDL_Rect calculateRect(const int & linearIndex, const int & gridCellWidth, const int & gridCellHeight);

IMenuProperties *mIMenuProperties;
std::vector<UIGridCell> mUIGridCells;

bool mHidden;

};
