class UIElement
{
public:

UIElement();
~UIElement();

const SDL_Rect & getRect();

private:

SDL_Rect mRect;

};
