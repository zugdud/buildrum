class UIButtonState
{
public:

UIButtonState();
~UIButtonState();

const UIButtonStateProperties & getUIButtonStateProperties() const;
void configure(const UIButtonStateProperties &uiButtonStateProperties);

private:

UIButtonStateProperties mUIButtonStateProperties;

};
