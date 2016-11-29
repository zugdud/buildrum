class UIMenu : public UIElement
{
public:

UIMenu(const IUIMenuProperties & menuProperties, const SDL_Rect & envelope);
~UIMenu();

private:

IUIMenuProperties mIUIMenuProperties;

std::vector<UIButton> mUIButtons;
std::vector<UILabel> mUILabels;

};
