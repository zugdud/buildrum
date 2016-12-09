#include "include/global.hpp"

WorldManager::WorldManager()
{

}

WorldManager::~WorldManager()
{

}

WorldManager::loadWorld()
{
    mWorld = GenerateWorld("testWorld");
}
