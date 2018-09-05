LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE_PATH := $(TARGET_OUT_SHARED_LIBRARIES)

LOCAL_LDLIBS := -llog

LOCAL_SRC_FILES:= \
	native-lib.cpp \

LOCAL_MODULE := nativelib

APP_ABI := armeabi-v7a

LOCAL_MODULE_TAGS := optional

include $(BUILD_SHARED_LIBRARY)