#
# 'make depend' uses makedepend to automatically generate dependencies
#               (dependencies are added to end of Makefile)
# 'make'        build executable file 'mycc'
# 'make clean'  removes all .o and executable files
#

# define the C compiler to use
CC = g++

# define any compile-time flags
CFLAGS = -Wall -g

CURRENTDIR=`pwd`

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
UTIL_DIR=util


# define any directories containing header files other than /usr/include
#
INCLUDES =-I/usr/include/SDL2/ \
-I/home/jcreecy/code/buildrum/ \
-I $(HEADER_DIR)/$(CONFIG_DIR) \
-I $(HEADER_DIR)/$(CONSTANTS_ACTORS_DIR) \
-I $(HEADER_DIR)/$(CONSTANTS_MEDIA_ENVIRONMENT_DIR) \
-I $(HEADER_DIR)/$(CONSTANTS_ENTITIES_DIR) \
-I $(HEADER_DIR)/$(CONSTANTS_MEDIA_FONTS_DIR) \
-I $(HEADER_DIR)/$(CONSTANTS_MEDIA_AUDIO_DIR) \
-I $(HEADER_DIR)/$(CONSTANTS_MEDIA_SPRITES_DIR) \
-I $(HEADER_DIR)/$(CONSTANTS_WINDOW_DIR) \
-I $(HEADER_DIR)/$(CONSTANTS_MENUS_DIR) \
-I $(HEADER_DIR)/$(CONSTANTS_MENUS_IMPL_DIR) \
-I $(HEADER_DIR)/$(WINDOW_DIR) \
-I $(HEADER_DIR)/$(EVENTS_DIR) \
-I $(HEADER_DIR)/$(EVENTS_HANDLERS_DIR) \
-I $(HEADER_DIR)/$(CORE_DIR) \
-I $(HEADER_DIR)/$(CORE_SCENES_DIR) \
-I $(HEADER_DIR)/$(INPUT_DIR) \
-I $(HEADER_DIR)/$(UI_DIR) \
-I $(HEADER_DIR)/$(UI_ELEMENTS) \
-I $(HEADER_DIR)/$(RENDERERS_DIR) \
-I $(HEADER_DIR)/$(MEDIA_FONTS_DIR) \
-I $(HEADER_DIR)/$(MEDIA_AUDIO_DIR) \
-I $(HEADER_DIR)/$(MEDIA_SPRITES_DIR) \
-I $(HEADER_DIR)/$(WORLD_ENTITIES_DIR) \
-I $(HEADER_DIR)/$(WORLD_GENERATOR_IMPL_DIR) \
-I $(HEADER_DIR)/$(WORLD_GENERATOR_DIR) \
-I $(HEADER_DIR)/$(WORLD_TILE_DIR) \
-I $(HEADER_DIR)/$(WORLD_DIR) \
-I $(HEADER_DIR)/$(AI_DIR) \
-I $(HEADER_DIR)/$(ACTORS_DIR) \
-I $(HEADER_DIR)/$(EVENTS_HANDLERS_DIR) \
-I $(HEADER_DIR)/$(EVENTS_HANDLERS_DIR) \
-I $(HEADER_DIR)/$(TYPES_DIR) \
-I $(HEADER_DIR)/$(UTIL_DIR) \

# define library paths in addition to /usr/lib
#   if I wanted to include libraries not in /usr/lib I'd specify
#   their path using -Lpath, something like:
LFLAGS =

# define any libraries to link into executable:
#   if I want to link in libraries (libx.so or libx.a) I use the -llibname
#   option, something like (this will link in libmylib.so and libm.so:
LIBS = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

# define the C source files
SRCS = main.cpp \
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
$(SRC_DIR)/$(EVENTS_HANDLERS_DIR)/HandleMoveCamera.cpp \
$(SRC_DIR)/$(EVENTS_HANDLERS_DIR)/HandleToggleBuildMenu.cpp \
$(SRC_DIR)/$(CORE_DIR)/GameInstance.cpp \
$(SRC_DIR)/$(CORE_DIR)/SceneManager.cpp \
$(SRC_DIR)/$(CORE_SCENES_DIR)/BaseScene.cpp \
$(SRC_DIR)/$(CORE_SCENES_DIR)/StartSceneImpl.cpp \
$(SRC_DIR)/$(CORE_SCENES_DIR)/GameSceneImpl.cpp \
$(SRC_DIR)/$(CORE_SCENES_DIR)/LoadingSceneImpl.cpp \
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
$(SRC_DIR)/$(ACTORS_DIR)/Player.cpp \
$(SRC_DIR)/$(UTIL_DIR)/Timer.cpp \
$(SRC_DIR)/$(UTIL_DIR)/TimerManager.cpp \
$(SRC_DIR)/$(AI_DIR)/Pathfinding.cpp \
$(SRC_DIR)/$(TYPES_DIR)/WeightedQueue.cpp

# define the C object files
#
# This uses Suffix Replacement within a macro:
#   $(name:string1=string2)
#         For each word in 'name' replace 'string1' with 'string2'
# Below we are replacing the suffix .c of all words in the macro SRCS
# with the .o suffix
#
OBJS = $(SRCS:.c=.o)

# define the executable file
MAIN = Buildrum.bin

#
# The following part of the makefile is generic; it can be used to
# build any executable just by changing the definitions above and by
# deleting dependencies appended to the file from 'make depend'
#

.PHONY: depend clean

all:    $(MAIN)
				@echo  Success! Complete

$(MAIN): $(OBJS)
				$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

# this is a suffix replacement rule for building .o's from .c's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .c file) and $@: the name of the target of the rule (a .o file)
# (see the gnu make manual section about automatic variables)
.c.o:
				$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
				$(RM) *.o *~ $(MAIN)

depend: $(SRCS)
				makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it
