class WorldManager
{
public:

static WorldManager& Instance()
{
    static WorldManager instance;

    return instance;
}

protected:

WorldManager();
WorldManager(const WorldManager&);
WorldManager& operator=(const WorldManager&);
~WorldManager();

private:

};
