enum PlayerActionState
{
    MOVE_ACTION,
    BUILD_ACTION
};

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

const PlayerActionState & getAction();
void setAction(const PlayerActionState & playerActionState);

protected:

Player();
Player(const Player&);
Player& operator=(const Player&);
~Player();

private:

PlayerActionState mPlayerActionState;

int mCredits;
BuildableObjectProperties mSelectedBuildableActionProperties;

bool mCameraControll;

};
