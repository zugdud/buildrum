const int arraySize = 256;

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
    std::string windowName;
    RGBAColors bgColor;
    int screenHeight;
    int screenWidth;
};

struct ViewportProperties
{
    std::string viewportId;
    double xPadRatio;
    double yPadRatio;
    double windowWidthRatio;
    double windowHeightRatio;
    RGBAColors bgColor;
};

struct CameraProperties
{
    double defaultZoomLevel;
    double maxZoomLevel;
    double minZoomLevel;
};

// ------------------------------------------------------------------------------
// UI Menus
// ------------------------------------------------------------------------------

struct UILabelProperties
{
    int orderId;
    std::string labelId;
    std::string labelText;
    std::string fontId;
};

struct UIButtonStateProperties
{
    std::string buttonState;
    int spriteId;
    std::string soundEffectId;
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
