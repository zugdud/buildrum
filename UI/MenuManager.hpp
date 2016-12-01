class MenuManager
{

public:

static MenuManager& Instance()
{
    static MenuManager instance;

    return instance;
}


void configure();
void repositionMenu(const std::string & menuId, const SDL_Rect & envelope);
const UIMenu & getUIMenu(const std::string & menuId);

protected:

MenuManager();
MenuManager(const MenuManager&);
MenuManager& operator=(const MenuManager&);
~MenuManager();

private:

std::map < std::string, UIMenu> mUiMenus;

};
