#include "include/global.hpp"

WorldManager::WorldManager()
{

}

WorldManager::~WorldManager()
{

}

void WorldManager::loadWorld(const std::string & worldId)
{
    SDL_Log("WorldManager::loadWorld -- worldId: %s \n", worldId.c_str());
    GenerateWorld generateWorld;
    generateWorld.createWorld(worldId);
    mWorld = generateWorld.getWorld();

    generateWorld.setPaths();
}

const World & WorldManager::getWorld() const
{
    return mWorld;
}

World * WorldManager::getWorldPtr()
{
    return &mWorld;
}
