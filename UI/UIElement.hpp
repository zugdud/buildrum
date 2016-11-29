class UIElement
{

public:

UIElement();
~UIElement();

protected:

const SDL_Rect & getRect();
void setRect(const int & xPadding, const int & yPadding, const SDL_Rect & envelope);
void logDimensions(const std::string & name);

private:

SDL_Rect mRect;

};
