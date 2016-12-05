class IRenderer
{
public:

virtual void renderAllLayers() = 0;
virtual std::vector<UIMenu *> & getAllLayers() = 0;

};
