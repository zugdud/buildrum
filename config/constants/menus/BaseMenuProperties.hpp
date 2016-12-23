class BaseMenuProperties : public IMenuProperties
{
public:

BaseMenuProperties();
~BaseMenuProperties();

const UIMenuProperties & getUIMenuProperties() const;
const std::vector<UIButtonProperties> & getUIButtonProperties();
const std::vector<UIButtonStateProperties> & getUIButtonStateProperties(const std::string & buttonId);
const std::vector<UILabelProperties> & getUILabelProperties();

protected:

void setUIButtonStateProperties(const std::string & buttonId, const int & spriteId, const std::string & spriteSheetIds, const bool & showBgSprite);

UIMenuProperties mUIMenuProperties;
std::vector<UIButtonProperties> mUIButtonProperties;
std::map<std::string, std::vector<UIButtonStateProperties> > mUIButtonStateProperties;   // buttonID->button states
std::vector<UILabelProperties> mUILabelProperties;

};
