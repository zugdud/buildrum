class UIElement
{

public:

UIElement();
~UIElement();

const SDL_Rect & getRect() const;

protected:

void setRect(const int & xPadding, const int & yPadding, const SDL_Rect & envelope);
void logRectDimensions(const std::string & elementType, const std::string & elementName, const SDL_Rect & rect);

private:

SDL_Rect mRect;

};
