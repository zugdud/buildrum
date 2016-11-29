class MainMenuProperties
{
public:

MainMenuProperties();
~MainMenuProperties();


private:

UIMenuProperties mUIMenuProperties;
std::vector<UIButtonProperties> mUIButtonProperties;
std::vector<UIButtonStateProperties> mUIButtonStateProperties;
std::vector<UILabelProperties> mUILabelProperties;

};
