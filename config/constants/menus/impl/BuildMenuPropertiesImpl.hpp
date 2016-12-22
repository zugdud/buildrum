class BuildMenuPropertiesImpl : public IMenuProperties
{
public:

BuildMenuPropertiesImpl();
~BuildMenuPropertiesImpl();

void setProperties();

const UIMenuProperties & getUIMenuProperties() const;
const std::vector<UIButtonProperties> & getUIButtonProperties();
const std::vector<UIButtonStateProperties> & getUIButtonStateProperties();
const std::vector<UILabelProperties> & getUILabelProperties();

private:

void setUIMenuProperties();
void setButtonProperties();
void setUILabelProperties();

void setUIButtonStateProperties(const std::string & buttonId, const int & spriteId, const std::string & spriteSheetId);

UIMenuProperties mUIMenuProperties;
std::vector<UIButtonProperties> mUIButtonProperties;
std::vector<UIButtonStateProperties> mUIButtonStateProperties;
std::vector<UILabelProperties> mUILabelProperties;

};
