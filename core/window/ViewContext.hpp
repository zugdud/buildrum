class ViewContext
{
public:

ViewContext(const ViewContextProperties &ViewContextProperties);
~ViewContext();

const std::vector<Viewport> & getViewports();

private:

ViewContextProperties mViewContextProperties;
std::vector<Viewport> mViewports;

};
