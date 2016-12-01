#include "include/global.hpp"

ViewContext::ViewContext(const ViewContextProperties &ViewContextProperties)
{
    mViewContextProperties = ViewContextProperties;
}

ViewContext::~ViewContext()
{

}

void ViewContext::createViewports()
{
    const std::vector<ViewContextProperties> & viewContextProperties = mWindowPropertiesImpl.getViewContextProperties();

    for (size_t i = 0; i < viewContextProperties.size(); i++)
    {
        Viewport viewport = Viewport(viewportProperties[i], mWindowPropertiesImpl.getWindowProperties());
        // mViewports.push_back(viewport);
    }
}
