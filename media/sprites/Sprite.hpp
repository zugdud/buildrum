class Sprite
{
public:

Sprite(const int & spriteId, const SDL_Rect & rect);
~Sprite();

private:

int mSpriteId;
SDL_Rect mRect;

};
