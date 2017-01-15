class UIButtonState
{
public:

UIButtonState();
~UIButtonState();

const UIButtonStateProperties & getUIButtonStateProperties() const;
void updateSpriteName(const std::string & spriteName);

void configure(const UIButtonStateProperties &uiButtonStateProperties);

private:

UIButtonStateProperties mUIButtonStateProperties;

};
