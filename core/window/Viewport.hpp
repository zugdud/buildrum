class Viewport
{
public:

Viewport(const ViewportProperties &viewportProperties, const WindowProperties &windowProperties);
~Viewport();

const SDL_Rect & getRect() const;
const ViewportProperties & getViewportProperties() const;
bool isViewport(const std::string & viewportId) const;

private:

void setViewport(const WindowProperties &windowProperties);

ViewportProperties mViewportProperties;
SDL_Rect mViewport;

};
