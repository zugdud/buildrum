class Sprite
{
public:

Sprite(const int & spriteId, const SDL_Rect & rect);
~Sprite();

const int & getSpriteId() const;
const SDL_Rect & getRect() const;

private:

int mSpriteId;
SDL_Rect mRect;

};
