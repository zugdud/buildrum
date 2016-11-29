class IMenuProperties
{
public:

const UIMenuProperties & getUIMenuProperties() = 0;
const std::vector<UIButtonProperties> & getUIButtonProperties() = 0;
const std::vector<UIButtonStateProperties> & getUIButtonStateProperties() = 0;
const std::vector<UILabelProperties> & getUILabelProperties() = 0;

};
