class WorldManager
{
public:

static WorldManager& Instance()
{
    static WorldManager instance;

    return instance;
}

void loadWorld(const std::string & worldId);
const World & getWorld() const;

protected:

WorldManager();
WorldManager(const WorldManager&);
WorldManager& operator=(const WorldManager&);
~WorldManager();

private:

World mWorld;

};
