#include "include/global.hpp"


static int TestThread(void *ptr)
{
    int cnt;

    for (cnt = 0; cnt < 10; ++cnt)
    {
        printf("Thread counter: %d \n", cnt);
        SDL_Delay(500);
    }

    return cnt;
}

void startThread()
{
    SDL_Thread *thread;

    // int threadReturnValue;

    printf("SDL_CreateThread test: \n");
    thread = SDL_CreateThread(TestThread, "TestThread", (void *) NULL);

    if (NULL == thread)
    {
        printf("SDL_CreateThread failed: %s\n", SDL_GetError());
    }
    // else
    // {
    //     SDL_WaitThread(thread, &threadReturnValue);
    // }
}

int main(int argc, char *args[])
{
    // startThread();

    GameInstance gameInstance;

    if (gameInstance.init())
    {
        gameInstance.showStartScreen();
        // gameInstance.showGameScene();
    }
    else
    {
        SDL_Log("main -- gameInstance.init error, exiting.");
    }
    return 0;
}
