class CameraPropertiesImpl
{
public:

CameraPropertiesImpl();
~CameraPropertiesImpl();

void loadAll();

const CameraProperties & getCameraProperties() const;

private:

void setCameraProperties();

CameraProperties mCameraProperties;

};
