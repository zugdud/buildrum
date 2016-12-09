#include "include/global.hpp"

GenerateWorld::GenerateWorld()
{

}

GenerateWorld::~GenerateWorld()
{

}

const World & GenerateWorld::getWorld()
{
    return mWorld;
}

void GenerateWorld::createWorld(const std::string & worldId)
{
    if (worldId == "testWorld")
    {
        SDL_Log("GenerateWorld::setWorld -- creating world, worldId: %s \n", worldId.c_str());
        mTestWorldImpl.setWorld(mWorld);
    }
}
