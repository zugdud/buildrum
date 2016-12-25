LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := main

SDL_PATH := ../SDL2

LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(SDL_PATH)/include /usr/include/SDL2/

# Add your application source files here...
LOCAL_SRC_FILES := $(SDL_PATH)/src/main/android/SDL_android_main.c \
main.cpp \
config/ConfigManager.cpp \
config/constants/actors/CameraPropertiesImpl.cpp \
config/constants/media/environment/EnvironmentMediaPropertiesImpl.cpp \
config/constants/entities/SurfacePropertiesImpl.cpp \
config/constants/entities/BuildableObjectPropertiesImpl.cpp \
config/constants/media/fonts/FontProfilesImpl.cpp \
config/constants/media/audio/AudioContentImpl.cpp \
config/constants/media/sprites/SpriteSheetPropertiesImpl.cpp \
config/constants/media/sprites/SpritePropertiesImpl.cpp \
config/constants/window/WindowPropertiesImpl.cpp \
config/constants/menus/BaseMenuProperties.cpp \
config/constants/menus/impl/MainMenuPropertiesImpl.cpp \
config/constants/menus/impl/ActionMenuPropertiesImpl.cpp \
config/constants/menus/impl/BuildMenuPropertiesImpl.cpp \
config/constants/menus/impl/SelectedActionMenuPropertiesImpl.cpp \
config/constants/menus/impl/StatusMenuPropertiesImpl.cpp \
window/Viewport.cpp \
window/Camera.cpp \
window/Window.cpp \
window/WindowManager.cpp \
window/ViewContext.cpp \
core/EventManager.cpp \
core/GameInstance.cpp \
core/SceneManager.cpp \
core/scenes/BaseScene.cpp \
core/scenes/StartSceneImpl.cpp \
core/scenes/GameSceneImpl.cpp \
input/InputEventManager.cpp \
input/InputMomentum.cpp \
UI/elements/UIElement.cpp \
UI/elements/UIButtonState.cpp \
UI/elements/UIButton.cpp \
UI/elements/UILabel.cpp \
UI/elements/UIGridCell.cpp \
UI/elements/UIMenu.cpp \
UI/MenuManager.cpp \
renderers/MenuRenderer.cpp \
renderers/WorldRenderer.cpp \
renderers/MinimapRenderer.cpp \
media/fonts/FontManager.cpp \
media/fonts/FontTextures.cpp \
media/audio/AudioManager.cpp \
media/sprites/Sprite.cpp \
media/sprites/SpriteSheet.cpp \
media/sprites/SpriteSheetManager.cpp \
world/entities/Entity.cpp \
world/entities/Surface.cpp \
world/generator/impl/TestWorldImpl.cpp \
world/generator/GenerateWorld.cpp \
world/Tile.cpp \
world/World.cpp \
world/WorldManager.cpp \

LOCAL_SHARED_LIBRARIES := SDL2 SDL2_image SDL2_mixer SDL2_ttf

LOCAL_LDLIBS := -lGLESv1_CM -lGLESv2 -llog

include $(BUILD_SHARED_LIBRARY)
