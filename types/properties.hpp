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
    RGBAColors bgColor;
};

struct CameraProperties
{
    int initPositionX;
    int initPositionY;
    double defaultZoomFactor;
    double maxZoomFactor;
    double minZoomFactor;
};

// ------------------------------------------------------------------------------
// UI Menus
// ------------------------------------------------------------------------------

struct UILabelProperties
{
    int orderId;
    std::string labelText;
    std::string fontId;
    int xPadding;
    int yPadding;
    bool isSpacer;
};

struct UIRenderCellDetails
{
    RGBAColors backgroundColor;
    RGBAColors outlineColor;
    bool showBorderColor;
    bool showBackgroundColor;
    int backgroundSpriteId;
    bool showbackgroundSprite;
};

struct UIButtonStateProperties
{
    std::string buttonStateId;
    int spriteId;
    std::string soundEffectId;
    UIRenderCellDetails uiRenderCellDetails;
};

struct UIButtonProperties
{
    int orderId;
    std::string buttonId;
    int xPadding;
    int yPadding;
    std::string actionId;
    std::string defaultButtonState;
    bool isSpacer;
};

struct UIMenuProperties
{
    std::string uiMenuId;
    std::string viewportId;
    int rows;
    int columns;
    int xPadding;
    int yPadding;
    UIRenderCellDetails uiRenderCellDetails;
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
    std::string fontName;
    int fontSize;
    std::string fileName;
    SDL_Color fontColor;
};

// ------------------------------------------------------------------------------
// Input
// ------------------------------------------------------------------------------

struct InputTouchEventProperties
{
    std::string viewportId;
    SDL_Rect triggerEventRect;
};

struct InputScrollEventProperties
{
    std::string viewportId;
    double scaleFactor;
    double minRate;
    double maxRate;
    int momentumMs;
};

struct InputPinchEventProperties
{
    std::string viewportId;
    double scaleFactor;
    double minRate;
    double maxRate;
};
