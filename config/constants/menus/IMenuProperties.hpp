class IMenuProperties
{
public:

virtual void setProperties() = 0;

virtual const UIMenuProperties & getUIMenuProperties() const = 0;
virtual const std::vector<UIButtonProperties> & getUIButtonProperties() = 0;
virtual const std::vector<UIButtonStateProperties> & getUIButtonStateProperties() = 0;
virtual const std::vector<UILabelProperties> & getUILabelProperties() = 0;

};
