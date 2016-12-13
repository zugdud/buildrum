class CameraPropertiesImpl
{
public:

CameraPropertiesImpl();
~CameraPropertiesImpl();

void loadAll();

const CameraProperties & getCameraProperties();

private:

void setCameraProperties();

CameraProperties mCameraProperties;

};
