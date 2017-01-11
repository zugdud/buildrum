class Player
{

public:

static Player& Instance()
{
    static Player instance;

    return instance;
}

const int & getCredits();
const BuildableObjectProperties & getSelectedBuildableObjectProperties();

void setBuildableAction(const std::string & entityId);
void configure();

protected:

Player();
Player(const Player&);
Player& operator=(const Player&);
~Player();

private:

bool mSelected;
int mCredits;
BuildableObjectProperties mSelectedBuildableActionProperties;

bool mCameraControll;

};
