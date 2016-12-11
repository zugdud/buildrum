
// ------------------------------------------------------------------------------
// Window
// ------------------------------------------------------------------------------

struct CameraProperties
{
    int initPositionX;
    int initPositionY;
    double defaultZoomFactor;
    double maxZoomFactor;
    double minZoomFactor;
};

struct WindowProperties
{
    std::string windowName;
    SDL_Color bgColor;
    int screenWidth;
    int screenHeight;
};

struct ViewportProperties
{
    std::string viewportId;
    double xPadRatio;
    double yPadRatio;
    double windowWidthRatio;
    double windowHeightRatio;
    SDL_Color bgColor;
    CameraProperties cameraProperties;
};

struct ViewContextProperties
{
    std::string viewContextId;
    int numViewports;
    ViewportProperties viewports[256];
};
