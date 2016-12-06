class Sprite
{
public:

Sprite(const int & spriteId, const int & linearIndex, const SDL_Rect & rect);
~Sprite();

private:

int mSpriteId;
int mLinearIndex;
SDL_Rect mRect;

};
