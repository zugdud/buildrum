class IRenderer
{
public:

virtual void addLayer(const UIMenu & uimenu) = 0;
virtual void renderAllLayers() = 0;
virtual void updatePositionAllLayers() = 0;
virtual std::vector<UIMenu> & getAllLayers() = 0;

};
