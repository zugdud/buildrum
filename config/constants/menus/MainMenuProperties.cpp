#include "include/global.hpp"

MainMenuProperties::MainMenuProperties()
{
    setViewports();
    setWindowProfiles();
}

MainMenuProperties::~MainMenuProperties()
{

}

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
