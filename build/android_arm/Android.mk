LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := main

SDL_PATH := ../SDL2

HEADER_DIR=headers
SRC_DIR=src

CONFIG_DIR=config
CONSTANTS_ACTORS_DIR=config/constants/actors
CONSTANTS_MEDIA_ENVIRONMENT_DIR=config/constants/media/environment
CONSTANTS_ENTITIES_DIR=config/constants/entities
CONSTANTS_MEDIA_FONTS_DIR=config/constants/media/fonts
CONSTANTS_MEDIA_AUDIO_DIR=config/constants/media/audio
CONSTANTS_MEDIA_SPRITES_DIR=config/constants/media/sprites
CONSTANTS_WINDOW_DIR=config/constants/window
CONSTANTS_MENUS_DIR=config/constants/menus
CONSTANTS_MENUS_IMPL_DIR=config/constants/menus/impl
WINDOW_DIR=window
EVENTS_DIR=events
EVENTS_HANDLERS_DIR=events/handlers
CORE_DIR=core
CORE_SCENES_DIR=core/scenes
INPUT_DIR=input
UI_DIR=UI
UI_ELEMENTS=UI/elements
RENDERERS_DIR=renderers
MEDIA_FONTS_DIR=media/fonts/
MEDIA_AUDIO_DIR=media/audio
MEDIA_SPRITES_DIR=media/sprites
WORLD_ENTITIES_DIR=world/entities
WORLD_GENERATOR_IMPL_DIR=world/generator/impl
WORLD_GENERATOR_DIR=world/generator
WORLD_TILE_DIR=world/tile
WORLD_DIR=world
AI_DIR=AI
TYPES_DIR=types
ACTORS_DIR=actors

# includes
LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(SDL_PATH)/include \
/usr/include/SDL2/ \
/opt/include/

# Add your application source files here...
LOCAL_SRC_FILES := $(SDL_PATH)/src/main/android/SDL_android_main.c \
main.cpp \
$(SRC_DIR)/$(CONFIG_DIR)/ConfigManager.cpp \
$(SRC_DIR)/$(CONSTANTS_ACTORS_DIR)/CameraPropertiesImpl.cpp \
$(SRC_DIR)/$(CONSTANTS_MEDIA_ENVIRONMENT_DIR)/EnvironmentMediaPropertiesImpl.cpp \
$(SRC_DIR)/$(CONSTANTS_ENTITIES_DIR)/SurfacePropertiesImpl.cpp \
$(SRC_DIR)/$(CONSTANTS_ENTITIES_DIR)/BuildableObjectPropertiesImpl.cpp \
$(SRC_DIR)/$(CONSTANTS_MEDIA_FONTS_DIR)/FontProfilesImpl.cpp \
$(SRC_DIR)/$(CONSTANTS_MEDIA_AUDIO_DIR)/AudioContentImpl.cpp \
$(SRC_DIR)/$(CONSTANTS_MEDIA_SPRITES_DIR)/SpriteSheetPropertiesImpl.cpp \
$(SRC_DIR)/$(CONSTANTS_MEDIA_SPRITES_DIR)/SpritePropertiesImpl.cpp \
$(SRC_DIR)/$(CONSTANTS_WINDOW_DIR)/WindowPropertiesImpl.cpp \
$(SRC_DIR)/$(CONSTANTS_MENUS_DIR)/BaseMenuProperties.cpp \
$(SRC_DIR)/$(CONSTANTS_MENUS_IMPL_DIR)/MainMenuPropertiesImpl.cpp \
$(SRC_DIR)/$(CONSTANTS_MENUS_IMPL_DIR)/ActionMenuPropertiesImpl.cpp \
$(SRC_DIR)/$(CONSTANTS_MENUS_IMPL_DIR)/BuildMenuPropertiesImpl.cpp \
$(SRC_DIR)/$(WINDOW_DIR)/Viewport.cpp \
$(SRC_DIR)/$(WINDOW_DIR)/Camera.cpp \
$(SRC_DIR)/$(WINDOW_DIR)/Window.cpp \
$(SRC_DIR)/$(WINDOW_DIR)/WindowManager.cpp \
$(SRC_DIR)/$(WINDOW_DIR)/ViewContext.cpp \
$(SRC_DIR)/$(EVENTS_DIR)/EventManager.cpp \
$(SRC_DIR)/$(EVENTS_HANDLERS_DIR)/HandleNewGame.cpp \
$(SRC_DIR)/$(EVENTS_HANDLERS_DIR)/HandleMainMenu.cpp \
$(SRC_DIR)/$(EVENTS_HANDLERS_DIR)/HandleExitGame.cpp \
$(SRC_DIR)/$(EVENTS_HANDLERS_DIR)/HandleBuildEvent.cpp \
$(SRC_DIR)/$(CORE_DIR)/GameInstance.cpp \
$(SRC_DIR)/$(CORE_DIR)/SceneManager.cpp \
$(SRC_DIR)/$(CORE_SCENES_DIR)/BaseScene.cpp \
$(SRC_DIR)/$(CORE_SCENES_DIR)/StartSceneImpl.cpp \
$(SRC_DIR)/$(CORE_SCENES_DIR)/GameSceneImpl.cpp \
$(SRC_DIR)/$(INPUT_DIR)/InputEventManager.cpp \
$(SRC_DIR)/$(INPUT_DIR)/InputMomentum.cpp \
$(SRC_DIR)/$(UI_ELEMENTS)/UIElement.cpp \
$(SRC_DIR)/$(UI_ELEMENTS)/UIButtonState.cpp \
$(SRC_DIR)/$(UI_ELEMENTS)/UIButton.cpp \
$(SRC_DIR)/$(UI_ELEMENTS)/UILabel.cpp \
$(SRC_DIR)/$(UI_ELEMENTS)/UIGridCell.cpp \
$(SRC_DIR)/$(UI_ELEMENTS)/UIMenu.cpp \
$(SRC_DIR)/$(UI_DIR)/MenuManager.cpp \
$(SRC_DIR)/$(RENDERERS_DIR)/BaseRenderer.cpp \
$(SRC_DIR)/$(RENDERERS_DIR)/MenuRenderer.cpp \
$(SRC_DIR)/$(RENDERERS_DIR)/WorldRenderer.cpp \
$(SRC_DIR)/$(RENDERERS_DIR)/MinimapRenderer.cpp \
$(SRC_DIR)/$(RENDERERS_DIR)/SelectedActionMenuRenderer.cpp \
$(SRC_DIR)/$(RENDERERS_DIR)/StatusMenuRenderer.cpp \
$(SRC_DIR)/$(MEDIA_FONTS_DIR)/FontManager.cpp \
$(SRC_DIR)/$(MEDIA_FONTS_DIR)/FontTextures.cpp \
$(SRC_DIR)/$(MEDIA_AUDIO_DIR)/AudioManager.cpp \
$(SRC_DIR)/$(MEDIA_SPRITES_DIR)/Sprite.cpp \
$(SRC_DIR)/$(MEDIA_SPRITES_DIR)/SpriteSheet.cpp \
$(SRC_DIR)/$(MEDIA_SPRITES_DIR)/SpriteSheetManager.cpp \
$(SRC_DIR)/$(WORLD_ENTITIES_DIR)/Entity.cpp \
$(SRC_DIR)/$(WORLD_ENTITIES_DIR)/Surface.cpp \
$(SRC_DIR)/$(WORLD_ENTITIES_DIR)/BuildableObject.cpp \
$(SRC_DIR)/$(WORLD_GENERATOR_IMPL_DIR)/TestWorldImpl.cpp \
$(SRC_DIR)/$(WORLD_GENERATOR_DIR)/GenerateWorld.cpp \
$(SRC_DIR)/$(WORLD_DIR)/Tile.cpp \
$(SRC_DIR)/$(WORLD_DIR)/World.cpp \
$(SRC_DIR)/$(WORLD_DIR)/WorldManager.cpp \
$(SRC_DIR)/$(ACTORS_DIR)/Player.cpp

LOCAL_SHARED_LIBRARIES := SDL2 SDL2_image SDL2_mixer SDL2_ttf

LOCAL_LDLIBS := -lGLESv1_CM -lGLESv2 -llog

include $(BUILD_SHARED_LIBRARY)
