class IRenderer
{
public:

virtual void renderAllLayers() = 0;
virtual std::vector<UIMenu *> & getAllLayers() = 0;

};

class IWorldRenderer
{
public:

virtual void renderWorld() = 0;

};

class IMinimapRenderer
{
public:

virtual void render() = 0;

};
