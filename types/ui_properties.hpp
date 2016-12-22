
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
    SpriteProperties spriteProperties;
    bool showbackgroundSprite;
};

struct UIButtonStateProperties
{
    std::string buttonId;
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
    bool hidden;
};
