#!/bin/bash
source env.sh $1

echo " --- COPY SRC AND BUILD ---- "
rm -rf /opt/sdl_android/SDL2-2.0.4/android-project/jni/src/*
cp -r /home/jcreecy/code/buildrum/build/android_arm/* /opt/sdl_android/SDL2-2.0.4/android-project/jni/src/
cp -r /home/jcreecy/code/buildrum/* /opt/sdl_android/SDL2-2.0.4/android-project/jni/src/

./headerLinks.sh

# ndk build
echo "--- STARTING NDK BUILD ---"
cd $SRC_DIR
ndk-build

# build apk
echo "--- STARTING APK BUILD ---"
cd $ANDROID_PROJECT
ant clean
ant debug
rm ${OUT_DIR}/*.apk
cp ${TMP_DIR}/${EXE_NAME} ${OUT_DIR}/${PACKAGE_NAME}
