const int arraySize = 256;

struct GameInstanceProperties
{
    WindowProperties windowProperties;
    CameraProperties cameraProperties;
}

// ------------------------------------------------------------------------------
// Env
// ------------------------------------------------------------------------------

struct EnvironmentMediaProperties
{
    std::string mediaDirBasePath;
    std::string imageDirName;
    std::string soundEffectDirName;
    std::string musicTrackDirName;
    std::string fontDirName;
};

// ------------------------------------------------------------------------------
// Window
// ------------------------------------------------------------------------------

struct WindowProperties
{
    int screenHeight;
    int screenWidth;
    int numViewports;
    ViewportProperties Viewports[arraySize];
    std::string windowId;
};

struct ViewportProperties
{
    std::string viewportId;
    int xPositionOffset;
    int yPositionOffset;
    double windowWidthRatio;
    double windowHeightRatio;
};

struct CameraProperties
{
    int levelWidth;
    int levelHeight;
    double defaultZoomLevel;
    double maxZoomLevel;
    double minZoomLevel;
};

// ------------------------------------------------------------------------------
// UI Menus
// ------------------------------------------------------------------------------

struct UIMenuProperties
{
    std::string mUIMenuId;
    std::string mViewportId;
    int mRows;
    int mColumns;
    int mNumPanes;
    UIPaneProperties UIPanes[arraySize];
    int xPadding;
    int yPadding;
};

struct UIPaneProperties
{
    std::string uiPaneId;
    int xPadding;
    int yPadding;
    int gridId;
    int spriteId;
    int numButtons;
    UIButtonProperties buttons[arraySize];
    int numLabels;
    UILabelProperties labels[arraySize];
};

struct UIButtonProperties
{
    int orderId;
    std::string buttonId;
    int xPadding;
    int yPadding;
    std::string actionId;
    int numButtonStates;
    UIButtonStateProperties buttonStates[arraySize];

};

struct UIButtonStateProperties
{
    std::string buttonState;
    int spriteId;
    std::string soundEffectId;
};

struct UILabelProperties
{
    int orderId;
    std::string labelId;
    std::string labelText;
    std::string fontId;
};

// ------------------------------------------------------------------------------
// Media
// ------------------------------------------------------------------------------

struct SpriteSheetProperties
{
    int spriteSheetId;
    int rows;
    int columns;
    int startSpriteId;
    int endSpriteId;
    int spriteSize;
    int spriteCount;
    int spriteSheetPixelWidth;
    int spriteSheetPixelHeight;
    std::string fileName;
};

struct SoundEffectProperties
{
    int soundEffectId;
    std::string fileName;
};

struct MusicTrackProperties
{
    int musicTrackId;
    std::string fileName;
};

struct FontProperties
{
    int fontId;
    std::string fileName;
};
