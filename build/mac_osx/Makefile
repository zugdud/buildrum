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
# define any directories containing header files other than /usr/include
#

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
TYPES_DIR=types
ACTORS_DIR=actors

INCLUDES =-I/usr/include/SDL2/ \
 -I /Library/Frameworks/SDL2.framework/Headers \
 -I /Library/Frameworks/SDL2_image.framework/Headers \
 -I /Library/Frameworks/SDL2_ttf.framework/Headers \
 -I /Library/Frameworks/SDL2_mixer.framework/Headers \
 -I /Users/jcreecy/code/buildrum \
 -F/Library/Frameworks \
 -I $(CONFIG_DIR) \
 -I $(CONSTANTS_ACTORS_DIR) \
 -I $(CONSTANTS_MEDIA_ENVIRONMENT_DIR) \
 -I $(CONSTANTS_ENTITIES_DIR) \
 -I $(CONSTANTS_MEDIA_FONTS_DIR) \
 -I $(CONSTANTS_MEDIA_AUDIO_DIR) \
 -I $(CONSTANTS_MEDIA_SPRITES_DIR) \
 -I $(CONSTANTS_WINDOW_DIR) \
 -I $(CONSTANTS_MENUS_DIR) \
 -I $(CONSTANTS_MENUS_IMPL_DIR) \
 -I $(WINDOW_DIR) \
 -I $(EVENTS_DIR) \
 -I $(EVENTS_HANDLERS_DIR) \
 -I $(CORE_DIR) \
 -I $(CORE_SCENES_DIR) \
 -I $(INPUT_DIR) \
 -I $(UI_DIR) \
 -I $(UI_ELEMENTS) \
 -I $(RENDERERS_DIR) \
 -I $(MEDIA_FONTS_DIR) \
 -I $(MEDIA_AUDIO_DIR) \
 -I $(MEDIA_SPRITES_DIR) \
 -I $(WORLD_ENTITIES_DIR) \
 -I $(WORLD_GENERATOR_IMPL_DIR) \
 -I $(WORLD_GENERATOR_DIR) \
 -I $(WORLD_TILE_DIR) \
 -I $(WORLD_DIR) \
 -I $(ACTORS_DIR) \
 -I $(EVENTS_HANDLERS_DIR) \
 -I $(EVENTS_HANDLERS_DIR) \
 -I $(TYPES_DIR) \

# define library paths in addition to /usr/lib
#   if I wanted to include libraries not in /usr/lib I'd specify
#   their path using -Lpath, something like:
LFLAGS =

# define any libraries to link into executable:
#   if I want to link in libraries (libx.so or libx.a) I use the -llibname
#   option, something like (this will link in libmylib.so and libm.so:
LIBS = -framework SDL2 -framework SDL2_image -framework SDL2_mixer -framework SDL2_ttf

# define the C source files
SRCS = main.cpp \
$(CONFIG_DIR)/ConfigManager.cpp \
$(CONSTANTS_ACTORS_DIR)/CameraPropertiesImpl.cpp \
$(CONSTANTS_MEDIA_ENVIRONMENT_DIR)/EnvironmentMediaPropertiesImpl.cpp \
$(CONSTANTS_ENTITIES_DIR)/SurfacePropertiesImpl.cpp \
$(CONSTANTS_ENTITIES_DIR)/BuildableObjectPropertiesImpl.cpp \
$(CONSTANTS_MEDIA_FONTS_DIR)/FontProfilesImpl.cpp \
$(CONSTANTS_MEDIA_AUDIO_DIR)/AudioContentImpl.cpp \
$(CONSTANTS_MEDIA_SPRITES_DIR)/SpriteSheetPropertiesImpl.cpp \
$(CONSTANTS_MEDIA_SPRITES_DIR)/SpritePropertiesImpl.cpp \
$(CONSTANTS_WINDOW_DIR)/WindowPropertiesImpl.cpp \
$(CONSTANTS_MENUS_DIR)/BaseMenuProperties.cpp \
$(CONSTANTS_MENUS_IMPL_DIR)/MainMenuPropertiesImpl.cpp \
$(CONSTANTS_MENUS_IMPL_DIR)/ActionMenuPropertiesImpl.cpp \
$(CONSTANTS_MENUS_IMPL_DIR)/BuildMenuPropertiesImpl.cpp \
$(WINDOW_DIR)/Viewport.cpp \
$(WINDOW_DIR)/Camera.cpp \
$(WINDOW_DIR)/Window.cpp \
$(WINDOW_DIR)/WindowManager.cpp \
$(WINDOW_DIR)/ViewContext.cpp \
$(EVENTS_DIR)/EventManager.cpp \
$(EVENTS_HANDLERS_DIR)/HandleNewGame.cpp \
$(EVENTS_HANDLERS_DIR)/HandleMainMenu.cpp \
$(EVENTS_HANDLERS_DIR)/HandleExitGame.cpp \
$(EVENTS_HANDLERS_DIR)/HandleBuildEvent.cpp \
$(CORE_DIR)/GameInstance.cpp \
$(CORE_DIR)/SceneManager.cpp \
$(CORE_SCENES_DIR)/BaseScene.cpp \
$(CORE_SCENES_DIR)/StartSceneImpl.cpp \
$(CORE_SCENES_DIR)/GameSceneImpl.cpp \
$(INPUT_DIR)/InputEventManager.cpp \
$(INPUT_DIR)/InputMomentum.cpp \
$(UI_ELEMENTS)/UIElement.cpp \
$(UI_ELEMENTS)/UIButtonState.cpp \
$(UI_ELEMENTS)/UIButton.cpp \
$(UI_ELEMENTS)/UILabel.cpp \
$(UI_ELEMENTS)/UIGridCell.cpp \
$(UI_ELEMENTS)/UIMenu.cpp \
$(UI_DIR)/MenuManager.cpp \
$(RENDERERS_DIR)/MenuRenderer.cpp \
$(RENDERERS_DIR)/WorldRenderer.cpp \
$(RENDERERS_DIR)/MinimapRenderer.cpp \
$(RENDERERS_DIR)/SelectedActionMenuRenderer.cpp \
$(RENDERERS_DIR)/StatusMenuRenderer.cpp \
$(MEDIA_FONTS_DIR)/FontManager.cpp \
$(MEDIA_FONTS_DIR)/FontTextures.cpp \
$(MEDIA_AUDIO_DIR)/AudioManager.cpp \
$(MEDIA_SPRITES_DIR)/Sprite.cpp \
$(MEDIA_SPRITES_DIR)/SpriteSheet.cpp \
$(MEDIA_SPRITES_DIR)/SpriteSheetManager.cpp \
$(WORLD_ENTITIES_DIR)/Entity.cpp \
$(WORLD_ENTITIES_DIR)/Surface.cpp \
$(WORLD_ENTITIES_DIR)/BuildableObject.cpp \
$(WORLD_GENERATOR_IMPL_DIR)/TestWorldImpl.cpp \
$(WORLD_GENERATOR_DIR)/GenerateWorld.cpp \
$(WORLD_DIR)/Tile.cpp \
$(WORLD_DIR)/World.cpp \
$(WORLD_DIR)/WorldManager.cpp \
$(ACTORS_DIR)/Player.cpp

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
