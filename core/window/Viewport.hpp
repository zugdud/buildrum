class Viewport
{
public:

Viewport(const ViewportProperties &viewportProperties, const WindowProperties &windowProperties);
~Viewport();

const SDL_Rect & getRect();

private:

void setViewport(const WindowProperties &windowProperties);

ViewportProperties mViewportProperties;
SDL_Rect mViewport;

};
