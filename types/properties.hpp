// ------------------------------------------------------------------------------
// Env
// ------------------------------------------------------------------------------

struct EnvironmentMediaProperties
{
    std::string spriteSheetDirPath;
    std::string soundEffectDirPath;
    std::string musicTrackDirPath;
    std::string fontDirPath;
};

// ------------------------------------------------------------------------------
// Window
// ------------------------------------------------------------------------------

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
};

struct ViewContextProperties
{
    std::string viewContextId;
    int numViewports;
    ViewportProperties viewports[256];
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
// Scene
// ------------------------------------------------------------------------------

// ------------------------------------------------------------------------------
// UI Menus
// ------------------------------------------------------------------------------

struct UILabelProperties
{
    int orderId;
    std::string labelText;
    std::string fontProfileName;
    int xPadding;
    int yPadding;
    bool isSpacer;
    std::string alignment;
};

struct UIRenderCellDetails
{
    SDL_Color backgroundColor;
    SDL_Color outlineColor;
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
    std::string spriteSheetId;
    std::string fileName;
    int rows;
    int columns;
    int spriteSize;
    int spriteCount;
    int sheetPixelWidth;
    int sheetPixelHeight;
    SDL_Color colorKey;
};


struct AudioPlayerProperties
{
    int frequency;
    Uint16 format;
    int channels;
    int chunksize;
    std::string defaultMusicTrackId;
};


struct SoundEffectProperties
{
    std::string soundEffectId;
    std::string fileName;
};

struct MusicTrackProperties
{
    std::string musicTrackId;
    std::string fileName;
};

struct FontProfile
{
    std::string fontProfileName;
    int fontSize;
    std::string filePath;
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
