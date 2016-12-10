#include "include/global.hpp"

WorldManager::WorldManager()
{

}

WorldManager::~WorldManager()
{

}

WorldManager::loadWorld(const std::string & worldId)
{
    SDL_Log("WorldManager::loadWorld -- worldId: %s \n", worldId.c_str());
    mWorld = GenerateWorld(worldId);
}
