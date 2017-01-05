class BaseRenderer
{
public:

BaseRenderer();
~BaseRenderer();

void renderSprite(const SpriteProperties & spriteProperties, const SDL_Rect & destRect);

protected:

SDL_Renderer *mSDLRenderer;

private:


};
