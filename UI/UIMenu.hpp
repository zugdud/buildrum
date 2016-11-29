class UIMenu : public UIElement
{
public:

UIMenu(const UIMenuProperties & UIMenuProperties, const SDL_Rect & envelope);
~UIMenu();

private:

UIMenuProperties mUIMenuProperties;
std::vector<UIButton> mUIButtons;
std::vector<UILabel> mUIButtonStateProperties;

};
