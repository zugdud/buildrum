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
