#!/bin/bash

ROOT_DIR=/opt/sdl_android/SDL2-2.0.4/android-project/jni/src
INCLUDE_DIR=/opt/include/

rm -rf $INCLUDE_DIR
mkdir -p $INCLUDE_DIR
cd $INCLUDE_DIR

addLink()
{
  FILES=$ROOT_DIR/headers/$1/*.hpp
  for f in $FILES
  do
    echo "Linking $f -> $INCLUDE_DIR"
    ln -s $f
  done
}

addLink config
addLink config/constants/actors
addLink config/constants/media/environment
addLink config/constants/entities
addLink config/constants/media/fonts
addLink config/constants/media/audio
addLink config/constants/media/sprites
addLink config/constants/window
addLink config/constants/menus
addLink config/constants/menus/impl
addLink window
addLink events
addLink events/handlers
addLink core
addLink core/scenes
addLink input
addLink UI
addLink UI/elements
addLink renderers
addLink media/fonts/
addLink media/audio
addLink media/sprites
addLink world/entities
addLink world/generator/impl
addLink world/generator
addLink world/tile
addLink world
addLink AI
addLink types
addLink actors
addLink util
