class Viewport
{
public:

Viewport(const ViewportProperties &viewportProperties, const WindowProperties &windowProperties);
~Viewport();

private:

setViewport(const WindowProperties &windowProperties);

ViewportProperties mViewportProperties;
SDL_Rect mViewport;

};
