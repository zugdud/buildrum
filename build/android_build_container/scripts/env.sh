set -o vi
export EDITOR=vi

export PATH=$PATH:/opt/sdl_android/jdk1.8.0_91/
export PATH=$PATH:/opt/sdl_android/jdk1.8.0_91/bin/
export C_INCLUDE_PATH=/usr/include/
export JAVA_HOME=/opt/sdl_android/jdk1.8.0_91/
export PATH=$PATH:/opt/sdl_android/android-ndk-r11c:/opt/sdl_android/android-sdk-linux/platform-tools:
export ANDROID_HOME=/opt/sdl_android/android-sdk-linux
export ANDROID_PROJECT=/opt/sdl_android/SDL2-2.0.4/android-project
export TMP_DIR=/opt/sdl_android/SDL2-2.0.4/android-project/bin
export ASSET_DIR=/opt/assets/sprites

export PATH=$PATH:/usr/local/lib
export BUILD_DIR=/opt/sdl_android/SDL2-2.0.4/android-project
export SRC_DIR=/opt/sdl_android/SDL2-2.0.4/android-project/jni
export OUT_DIR=/tmp/out
export EXE_NAME=Buildrum-debug.apk
export PACKAGE_NAME=${EXE_NAME}_v${1}_`date +%Y-%m-%d_%H:%M:%S`.apk


echo " --- BUILD ENV --- "

echo ASSET_DIR: $ASSET_DIR
echo ANDROID_HOME: $ANDROID_HOME
echo ANDROID_PROJECT: $ANDROID_PROJECT
echo JAVA_HOME: $JAVA_HOME
echo PATH: $PATH
echo BUILD_DIR: $SRC_DIR
echo SRC_DIR: $SRC_DIR
echo OUT_DIR: $OUT_DIR
echo PACKAGE_NAME: $PACKAGE_NAME
echo EXE_NAME: $EXE_NAME
echo TMP_DIR: $TMP_DIR
