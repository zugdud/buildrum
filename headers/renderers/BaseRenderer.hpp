class BaseRenderer
{
public:

BaseRenderer();
~BaseRenderer();

void renderSprite(const SpriteProperties & spriteProperties, const SDL_Rect & destRect);
void renderString(const std::string & text, const std::string & fontProfile, const SDL_Rect & cellRect);

protected:

SDL_Renderer *mSDLRenderer;

private:


};
