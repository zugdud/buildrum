class UIMenu : public UIElement
{
public:

UIMenu(const MenuPropertiesContainer & menuPropertiesContainer);
~UIMenu();

void resetPosition(const SDL_Rect & envelope);

private:

void regenerateButtons();
void regenerateLabels();

MenuPropertiesContainer mMenuPropertiesContainer;

std::vector<UIButton> mUIButtons;
std::vector<UILabel> mUILabels;

};
