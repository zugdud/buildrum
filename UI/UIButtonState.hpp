class UIButtonState
{
public:

UIButtonState(const UIButtonStateProperties & UIButtonStateProperties);
~UIButtonState();

const UIButtonStateProperties & getUIButtonStateProperties() const;


private:

UIButtonStateProperties mUIButtonStateProperties;

};
