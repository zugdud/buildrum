class WorldRenderer
{
public:

WorldRenderer();
~WorldRenderer();

void setWorld(const World & world);
void removeWorld();

void renderWorld();

private:

SDL_Renderer *mSDLRenderer;
World mWorld;

};
