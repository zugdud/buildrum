class Viewport
{
public:

Viewport(const ViewportProperties &viewportProperties, const WindowProperties &windowProperties);
~Viewport();

private:

void setViewport(const WindowProperties &windowProperties);

ViewportProperties mViewportProperties;
SDL_Rect mViewport;

};
