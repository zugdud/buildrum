LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := main

SDL_PATH := ../SDL2

LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(SDL_PATH)/include /usr/include/SDL2/

# Add your application source files here...
LOCAL_SRC_FILES := $(SDL_PATH)/src/main/android/SDL_android_main.c \
main.cpp \
config/ConfigManager.cpp \
config/constants/media/environment/EnvironmentMediaPropertiesImpl.cpp \
config/constants/media/fonts/FontProfilesImpl.cpp \
config/constants/media/audio/AudioContentImpl.cpp \
config/constants/window/WindowPropertiesImpl.cpp \
config/constants/menus/impl/MainMenuPropertiesImpl.cpp \
window/Viewport.cpp \
window/Window.cpp \
window/WindowManager.cpp \
window/ViewContext.cpp \
core/EventManager.cpp \
core/GameInstance.cpp \
input/InputEventHandler.cpp \
UI/elements/UIElement.cpp \
UI/elements/UIButtonState.cpp \
UI/elements/UIButton.cpp \
UI/elements/UILabel.cpp \
UI/elements/UIGridCell.cpp \
UI/elements/UIMenu.cpp \
UI/MenuManager.cpp \
renderers/MenuRenderer.cpp \
media/fonts/FontManager.cpp \
media/fonts/FontTextures.cpp \
media/audio/AudioManager.cpp

LOCAL_SHARED_LIBRARIES := SDL2 SDL2_image SDL2_mixer SDL2_ttf

LOCAL_LDLIBS := -lGLESv1_CM -lGLESv2 -llog

include $(BUILD_SHARED_LIBRARY)
