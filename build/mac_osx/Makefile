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
INCLUDES =-I/usr/include/SDL2/ \
 -I /Library/Frameworks/SDL2.framework/Headers \
 -I /Library/Frameworks/SDL2_image.framework/Headers \
 -I /Library/Frameworks/SDL2_ttf.framework/Headers \
 -I /Library/Frameworks/SDL2_mixer.framework/Headers \
 -I /Users/jcreecy/code/buildrum \
 -F/Library/Frameworks

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
config/ConfigManager.cpp \
config/constants/window/WindowPropertiesImpl.cpp \
config/containers/IMenuProperties.cpp \
config/constants/menus/impl/MainMenuPropertiesImpl.cpp \
core/window/Viewport.cpp \
core/window/Window.cpp \
core/window/WindowManager.cpp \
core/GameInstance.cpp \
input/InputEventTypeHandler.cpp \
UI/UIElement.cpp \
UI/UIButtonState.cpp \
UI/UIButton.cpp \
UI/UILabel.cpp \
UI/UIMenu.cpp

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
