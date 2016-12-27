class Player
{

public:

static Player& Instance()
{
    static Player instance;

    return instance;
}

const BuildableObjectProperties & getSelectedBuildableObjectProperties();
const bool & isSelected();

void setBuildableAction(const std::string & entityId);
void configure();

protected:

Player();
Player(const Player&);
Player& operator=(const Player&);
~Player();


private:

bool mSelected;
BuildableObjectProperties mSelectedBuildableActionProperties;

};
